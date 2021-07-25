#include <iostream>
using namespace std;
int n, k;
long long dp[11][11];
long long go(int n, int k) {
	if (n == k) return 1;
	if (k == 0) return 1;
	if (dp[n][k] != 0) return dp[n][k];
	dp[n][k] = (go(n - 1, k - 1) + go(n - 1, k));

	return dp[n][k];
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	//dp[0][0] = 1;
	cout << go(n, k);

}