#include <iostream>
#include <algorithm>
using namespace std;
int d[2][3], d2[2][3];
int n;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> d[1][j];
			d2[1][j] = d[1][j];
		}

		if (i > 0) {
			int first = max(d[0][0] + d[1][0], d[0][1] + d[1][0]);
			int second = max({ d[0][0] + d[1][1], d[0][1] + d[1][1], d[0][2] + d[1][1] });
			int third = max(d[0][2] + d[1][2], d[0][1] + d[1][2]);

			int first2 = min(d2[0][0] + d2[1][0], d2[0][1] + d2[1][0]);
			int second2 = min({ d2[0][0] + d2[1][1], d2[0][1] + d2[1][1], d2[0][2] + d2[1][1] });
			int third2 = min(d2[0][2] + d2[1][2], d2[0][1] + d2[1][2]);

			d[0][0] = first;
			d[0][1] = second;
			d[0][2] = third;

			d2[0][0] = first2;
			d2[0][1] = second2;
			d2[0][2] = third2;
		}
		else {
			d[0][0] = d2[0][0] = d[1][0];
			d[0][1] = d2[0][1] = d[1][1];
			d[0][2] = d2[0][2] = d[1][2];
		}
	}

	cout << max({ d[0][0],d[0][1], d[0][2] }) << ' ' << min({ d2[0][0], d2[0][1], d2[0][2] });
}