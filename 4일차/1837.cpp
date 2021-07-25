#include <iostream>
#include <string>
using namespace std;
string p;
int k;
bool num[1000001];
bool divide(int x) {
	int ret = 0;
	for (int i = 0; i < p.length(); i++) {
		ret = (ret * 10 + (p[i] - '0')) % x;
	}

	if (ret == 0) return true;
	else return false;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> p >> k;

	for (int i = 2; i <= k; i++) {
		if (num[i] == true) continue;
		for (int j = i * 2; j <= k; j += i) {
			num[j] = true;
		}
	}

	bool check = false;
	for (int i = 2; i < k; i++) {
		if (num[i] == false) {
			//cout << i << '\n';
			if (divide(i)) {
				check = true;
				cout << "BAD " << i;
				break;
			}
		}
	}

	if(!check)
		cout << "GOOD";

	
}