#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
vector <string> s;
vector <char> alpha;
map<char, int> m;
bool check[12];
long long ans;
void go(int idx, int cnt) {
	if (cnt == alpha.size()) {
		long long x = 0;
		long long sum = 0;
		for (int i = 0; i < s.size(); i++) {
			x = 0;
			for (int j = 0; j < s[i].length(); j++) {
				//cout << m[s[i][j]] << ' ' << s[i][j] << '\n';
				x += m[s[i][j]];
				x *= 10;
			}
			//cout << x << '\n';
			x = x / 10;
			sum += x;
		}
		
		ans = max(ans, sum);
		return;
	}

	for (int i = 9; i >= 10 - alpha.size(); i--) {
		if (i == -1) break;
		if (!check[i]) {
			//cout << alpha[idx] << ' ' << i << '\n';
			check[i] = true;
			m[alpha[idx]] = i;
			go(idx + 1, cnt + 1);
			check[i] = false;
			//m[alpha[idx]] = -1;
		}
	}

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (m[temp[j]] == 0) {
				m[temp[j]] = 1;
				alpha.push_back(temp[j]);
			}
		}
		s.push_back(temp);
	}

	go(0, 0);

	cout << ans;
}