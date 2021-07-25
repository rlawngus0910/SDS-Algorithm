#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K;
int d[201][201];
string ans;

int go(int x, int y) {
	if (x == y) return 1;
	if (y == 0) return 1;
	if (d[x][y] != 0) return d[x][y];
	d[x][y] = min((int)1e9, go(x - 1, y - 1) + go(x - 1, y));

	return d[x][y];
}
void query(int n, int m, int k) {
	if (n + m == 0) return;

	else if (n == 0) {
		ans.push_back('z');
		query(n, m - 1, k);
	}
	else if (m == 0) {
		ans.push_back('a');
		query(n - 1, m, k);
	}

	else {
		int leftCnt = go(n + m - 1, n - 1);

		if (k <= leftCnt) {
			ans.push_back('a');
			query(n - 1, m, k);
		}

		else {
			ans.push_back('z');
			query(n, m - 1, k - leftCnt);
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	if (go(N + M, M) < K) cout << "-1";
	else {
		query(N, M, K);
		cout << ans;
	}
	
}