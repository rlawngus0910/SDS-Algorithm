#include <iostream>
#include <algorithm>
using namespace std;
int n, k, ans;
string s[50];
bool learn[26];

void go(int idx, int cnt) {
	if (cnt == k) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			bool check = true;
			for (int j = 0; j < s[i].size(); j++) {
				if (learn[s[i][j] - 'a'] == false) {
					check = false;
					break;
				}
			}

			if (check) temp++;
		}
		ans = max(ans, temp);
		return;
	}


	for (int i = idx; i < 26; i++) {
		if (!learn[i]) {
			learn[i] = true;
			go(i, cnt + 1);
			learn[i] = false;
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	learn['a' - 'a'] = true;
	learn['n' - 'a'] = true;
	learn['t' - 'a'] = true;
	learn['i' - 'a'] = true;
	learn['c' - 'a'] = true;

	if (k < 5) {
		cout << "0";
		return 0;
	}
	
	go(0,5);

	cout << ans;
}