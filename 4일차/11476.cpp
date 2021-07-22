#include <iostream>
using namespace std;
int n;
int arr[1000001];
int lr[1000001];
int rl[1000001];
int ans = 0;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	lr[0] = arr[0];
	for (int i = 1; i < n; i++) {
		
		lr[i] = gcd(arr[i], lr[i - 1]);
	}

	rl[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {

		rl[i] = gcd(arr[i], rl[i + 1]);
	}

	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (ans < rl[i + 1]) {
				if (arr[i] % rl[i + 1] != 0) {
					ans = rl[i + 1];
					idx = arr[i];
				}
			}
		}
		else if(i == n - 1) {
			if (ans < lr[n - 2]) {
				if (arr[i] % lr[n - 2] != 0) {
					ans = lr[i - 1];
					idx = arr[i];
				}
			}
		}
		else {
			int value = gcd(lr[i - 1], rl[i + 1]);
			if (ans < value) {
				if (arr[i] % value  != 0) {
					ans = value;
					idx = arr[i];
				}
			}
		}
	}

	if (idx == -1) cout << "-1";
	else cout << ans << ' ' << idx;
}