#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int z;
long long s, t, r;
int gcd(int x, int y) {
	while (y != 0) {
		int r = x % y;
		x = y;
		y = r;
	}

	return x;
}

void extendGCD(long long a, long long b) {
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;

	long long temp;
	while (r1 != 0) {
		long long q = r0 / r1;

		temp = r0 - q * r1;
		r0 = r1;
		r1 = temp;

		temp = s0 - q * s1;
		s0 = s1;
		s1 = temp;

		temp = t0 - q * t1;
		t0 = t1;
		t1 = temp;
	}

	s = s0;
	t = t0;
	r = r0;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> z;
	while(z--) {
		int k, c;
		cin >> k >> c;

		if (1 % gcd(k, c) != 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		extendGCD(k, c);

		long long x0 = s;
		long long y0 = t;

		long long kFromY = (long long)ceil((double)y0 / (double)k) - 1;
		long long kFromX = (long long)ceil((double)-x0 / (double)c) - 1;
		long long h = min(kFromY, kFromX);

		long long y = y0 - k * h;
		if (y <= 1e9) cout << y << '\n';
		else cout << "IMPOSSIBLE\n";

	}

}