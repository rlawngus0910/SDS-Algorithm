#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, x;
vector <int> v;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(), v.end());
	cin >> m;
	while (m--) {
		cin >> x;
		bool check = false;
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] > x) {
				right = mid - 1;
			}
			else if (v[mid] < x) {
				left = mid + 1;
			}
			else if (v[mid] == x) {
				cout << "1\n";
				check = true;
				break;
			}
		}

		if (!check) cout << "0\n";
	}
}