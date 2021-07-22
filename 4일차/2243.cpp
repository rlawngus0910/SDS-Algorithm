#include <iostream>
using namespace std;
int n, s = 1048576;
int tree[2100001];

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

int query(int left, int right, int node, int cnt) {
	if (left == right) return left;
	int mid = (left + right) / 2;

	if (tree[node * 2] < cnt) {
		return query(mid + 1, right, node * 2 + 1, cnt - tree[node * 2]);
	}

	else {
		return query(left, mid, node * 2, cnt);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;


	while (n--) {
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b;
			int ans = query(1, 1000000, 1, b);
			cout << ans << '\n';
			update(1, 1000000, 1, ans, -1);

		}

		else if (a == 2) {
			cin >> b >> c;
			update(1, 1000000, 1, b, c);
		}
	}

}