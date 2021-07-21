#include <iostream>
#include <algorithm>
using namespace std;
int n, m, l, r,ans;
int arr[1000001];
bool check(int x) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > x) {
			sum += (arr[i] - x);
		}
	}

	if (sum >= m) return true;
	return false;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}
	l = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (check(mid)) {
			ans = max(mid, ans);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}