#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans;
int arr[10002];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int left = 1;
	int right = 1;
	int sum = arr[left];
	while (left <= n && right <= n) {
		
		if (sum < m) {
			sum += arr[++right];
		}
		else if (sum > m) {
			sum -= arr[left++];
		}
		else if (sum == m) {
			ans++;
			sum -= arr[left++];
		}
	}

	cout << ans;
}