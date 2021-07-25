#include <iostream>
using namespace std;
int c;
int d[1001][1001];
int gcd(int x, int y) {
	if (x == 1 || y == 1) return 1;
	
	while (1) {
		int r = x % y;
		x = y;
		y = r;

		if (r == 0) return x;
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> c;

	for (int i = 1; i <= 1000; i++) {
		for (int j = i + 1; j <= 1000; j++) {
			if (d[i][j] != 0) continue;
			d[i][j] = d[j][i] = gcd(i, j);
		}
	}
	while (c--) {
		int n, ans = 0;
		
		cin >> n;

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i == j) continue;
				if (d[i][j] == 1) {
					//cout << i << ' ' << j << '\n';
					ans += 2;
				}
			}
		}

		cout << ans + 3 << '\n';
	}
}