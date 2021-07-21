#include <iostream>
#include <algorithm>
using namespace std;
long long x, y, z;
int ans = 1e9 + 10;
bool check(int mid) {
	if (z < (y + mid) * 100 / (x + mid)) return true;
	return false;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> y;
	z = y * 100 / x;

	int left = 1;
	int right = 1000000000;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}
	if (ans == 1e9 + 10) cout << "-1";
	else cout << ans;
}