#include <iostream>
using namespace std;
long long n, q, s;
long long tree[270000];
void update(int left, int right, int node, int target, long long diff) {
	if (left > target || right < target) return;

	tree[node] += diff;
	if (left == right) return;

	int mid = (left + right) / 2;
	if (node < s) {
		update(left, mid, node * 2, target, diff);
		update(mid + 1, right, node * 2 + 1, target, diff);
	}
}
long long query(int left, int right, int node, int queryLeft, int queryRight) {
	if (node > s * 2) return 0;
	if (queryLeft > right || queryRight < left) return 0;

	if (queryLeft <= left && queryRight >= right) return tree[node];

	if (queryLeft > left || queryRight < right) {
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;

	s = 1;

	while (s < n) {
		s = s * 2;
	}


	for (int i = 1,x; i <= n; i++) {
		cin >> x;
		tree[s + i - 1] = x;
	}

	for (int i = s - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	
	while (q--) {
		long long x, y, a, b, ans;
		cin >> x >> y >> a >> b;

		if (x > y)
			ans = query(1, s, 1, y, x);
		else
			ans = query(1, s, 1, x, y);

		cout << ans << '\n';
		update(1, s, 1, a, b - tree[s + a - 1]);
	}
}