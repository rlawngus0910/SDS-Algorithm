#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int ans = 100005;
int arr[100003];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int left = 1;
	int right = 1;
	int sum = arr[1];
	while (left <= n && right <= n) {
		if (sum >= s) {
			if (left == right) {
				cout << "1";
				return 0;
			}
			else {
				ans = min(ans, right - left + 1);
				sum -= arr[left++];
			}
		}
		else {
			sum += arr[++right];
		}
	}
	if (ans == 100005) cout << "0";
	else cout << ans;
}