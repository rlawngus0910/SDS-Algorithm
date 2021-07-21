#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <long long> A;
vector <long long> B;
vector <long long> C;
vector <long long> D;

vector <long long> AB;
vector <long long> CD;
bool cmp(const long long& a, const long long& b) {
	return a > b;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			long long x;
			cin >> x;
			if (j == 0) A.push_back(x);
			else if(j == 1) B.push_back(x);
			else if (j == 2) C.push_back(x);
			else if (j == 3) D.push_back(x);

			//if (j == 0 || j == 1) AB.push_back(x);
			//else if (j == 2 || j == 3) CD.push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long sum = A[i] + B[j];
			AB.push_back(sum);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long sum = C[i] + D[j];
			CD.push_back(sum);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end(),cmp);

	int left = 0;
	int right = 0;
	long long sum = AB[0] + CD[0];
	long long ans = 0;
	while (left < AB.size() && right < CD.size()) {
		if (sum == 0) {
			
			long long targetAB = AB[left];
			long long targetCD = CD[right];

			long long leftCnt = 0;
			long long rightCnt = 0;

			while (left < AB.size() && AB[left] == targetAB ) {
				leftCnt++;
				left++;
			}

			while (right < CD.size() && CD[right] == targetCD ) {
				rightCnt++;
				right++;
			}

			ans += (leftCnt * rightCnt);

			if (left >= AB.size() || right >= CD.size()) break;
			sum = AB[left] + CD[right];
		}
		else if (sum > 0){
			if (right + 1 >= CD.size()) break;
			sum -= CD[right++];
			sum += CD[right];
		}

		else if (sum < 0) {
			if (left + 1 >= AB.size()) break;
			
			sum -= AB[left++];
			sum += AB[left];
		}
	}

	cout << ans;
}