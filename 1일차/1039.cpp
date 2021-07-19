#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int k, ans = -1;
bool visit[11][1000000];
void go(string num, int cnt) {
	if (num[0] == '0') {
		return;
	}

	if (cnt == k) {
		ans = max(ans, stoi(num));
		return;
	}

	for (int i = 0; i < num.length(); i++) {
		for (int j = i + 1; j < num.length(); j++) {
			
			swap(num[i], num[j]);
			if (!visit[cnt + 1][stoi(num)]) {
				visit[cnt + 1][stoi(num)] = true;
				go(num, cnt + 1);
			}
			swap(num[i], num[j]);
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> k;
	
	go(s, 0);
	cout << ans;
}