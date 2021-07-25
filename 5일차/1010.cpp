#include <iostream>
using namespace std;
int n, m, t;
int dp[31][31];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	dp[0][0] = 1;
	
	for (int i = 1; i < 30; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = 1;
			else if (i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	while (t--) {
		cin >> n >> m;
		cout << dp[m][n] << '\n';
	}
}