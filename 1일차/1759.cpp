#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int l, c;
vector <char> v;
vector <char> ans;
bool visit[16];
void go(int idx, int cnt) {
	if (cnt == l) {
		int mo = 0;
		int za = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				mo++;
			else za++;
		}
		if (mo < 1 || za < 2) return;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < c; i++) {
		ans.push_back(v[i]);
		go(i + 1, cnt + 1);
		ans.pop_back();
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char ch;
		cin >> ch;
		v.push_back(ch);
	}

	sort(v.begin(), v.end());

	go(0, 0);
}