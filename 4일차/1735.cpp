#include <iostream>
using namespace std;
int a, b, c, d;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d;

	int g = gcd(b, d);
	int gm = g * (b / g) * (d / g);

	int newa = a * (gm / b);
	int newb = c * (gm / d);

	int newg = gcd(newa + newb, gm);
	cout << (newa + newb) / newg << ' ' << gm / newg;
}