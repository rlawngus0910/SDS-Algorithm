#include <iostream>
using namespace std;
bool num[1000001];
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i * i <= 1000000; i++) {
		
		if (num[i] == true) continue;
		int n = i * 2;
		while (n <= 1000000) {
			num[n] = true;
			n = n += i;
		}
	}

	while (1) {
		int x;
		cin >> x;
		if (x == 0) break;
		for (int i = 3; i <= 1000000; i += 2) {
			if (num[i] == false) {
				if (num[x - i] == false) {
					cout << x << " = " << i << " + " << x - i << '\n';
					break;
				}
			}
		}
	}
	
}