#include <iostream>
using namespace std;
int n, m, k,s = 1;
long long tree[2100000];
void init() {
	for (int i = s - 1; i >= 1; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

void update(int left, int right, int node, int target, long long diff) {
	if (left > target || right < target) return;

	tree[node] += diff;
	if (node == s + target - 1) return;

	int mid = (left + right) / 2;
	if (node < s) {
		update(left, mid, node * 2, target, diff);
		update(mid + 1, right, node * 2 + 1, target, diff);
	}
}

long long query(int left, int right, int node, int queryLeft, int queryRight) {
	
	if (queryRight < left || queryLeft > right) return 0;

	else if (left >= queryLeft && right <= queryRight) return tree[node];
	
	else {
		int mid = (left + right) / 2;
		return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;

	while (s < n) {
		s = s * 2;
	}

	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		tree[s + i - 1] = x;
	}

	init();
	
	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - tree[s + b - 1];
			
			update(1, s, 1, b, diff);
		}
		else {
			cout << query(1, s, 1, b, c) << '\n';
		}
	}
}