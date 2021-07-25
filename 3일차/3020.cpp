#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, h;
vector <int> suk;
vector <int> jong;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h;
	for (int i = 1,x; i <= n; i++) {
		cin >> x;
		if (i % 2 != 0) {
			suk.push_back(x);
		}

		else {
			jong.push_back(x);
		}
	}

	sort(suk.begin(), suk.end());
	sort(jong.begin(), jong.end());

	int cnt = 0;
	int ans = 1e9;
	for (int i = 1; i <= h; i++) {
		int sukTemp = suk.size() - (lower_bound(suk.begin(), suk.end(), i) - suk.begin());
		int jongTemp = jong.size() - (upper_bound(jong.begin(), jong.end(), h - i) - jong.begin());

		if (ans > sukTemp + jongTemp) {
			ans = sukTemp + jongTemp;
			cnt = 1;
		}
		else if (ans == sukTemp + jongTemp) {
			cnt++;
		}
	}

	cout << ans << ' ' << cnt;
}