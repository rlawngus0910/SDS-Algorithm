#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long t, n, m;
long long A[1001], B[1001];
vector <long long> subA;
vector <long long> subB;
bool cmp(const long long& a, const long long& b) {
	return a > b;
}

long long checkA(long long x,long long l) {
	long long leftCnt = 0;
	for (long long i = l; i < subA.size(); i++) {
		if (subA[i] == x) leftCnt++;
		else break;
	}
	return leftCnt;
}

long long checkB(long long y, long long r) {
	long long rightCnt = 0;
	
	for (long long i = r; i < subB.size(); i++) {
		if (subB[i] == y) rightCnt++;
		else break;
	}
	return rightCnt;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];

	for (int i = 0; i < n; i++) {
		long long sum = A[i];
		subA.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += A[j];
			subA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = B[i];
		subB.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += B[j];
			subB.push_back(sum);
		}
	}

	sort(subA.begin(), subA.end());
	sort(subB.begin(), subB.end(), cmp);

    long long left = 0, right = 0;
	long long sum = subA[0] + subB[0];
	long long ans = 0;

	while (left < subA.size() && right < subB.size()) {
		if (sum == t) {
			long long lcnt = checkA(subA[left], left);
		    long long rcnt = checkB(subB[right], right);
			ans += (lcnt * rcnt);
			left += lcnt;
			right += rcnt;
			if (left >= subA.size() || right >= subB.size()) break;

			sum = subA[left] + subB[right];
		}

		else if (sum < t) {
			if (left + 1 == subA.size()) break;
			sum -= subA[left++];
			sum += subA[left];
		}

		else if (sum > t) {
			if (right + 1 == subB.size()) break;
			sum -= subB[right++];
			sum += subB[right];
		}
	}

	cout << ans;
}