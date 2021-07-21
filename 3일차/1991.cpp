#include <iostream>
using namespace std;
int n, tree[26][2];
void pre(int idx) {
	if (idx == -1) return;

	cout << (char)(idx + 'A');
	pre(tree[idx][0]);
	pre(tree[idx][1]);
}

void inorder(int idx) {
	if (idx == -1) return;

	inorder(tree[idx][0]);
	cout << (char)(idx + 'A');
	inorder(tree[idx][1]);
}

void post(int idx) {
	if (idx == -1) return;

	post(tree[idx][0]);
	post(tree[idx][1]);
	cout << (char)(idx + 'A');
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			tree[a - 'A'][0] = b - 'A';
		else
			tree[a - 'A'][0] = -1;

		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
		else
			tree[a - 'A'][1] = -1;
	}

	pre(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	post(0);
	cout << '\n';
}