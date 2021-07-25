#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, double> m;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int num = 0;
	string s;
	while (getline(cin, s)) {
		
		num++;
		m[s]++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ' ' << iter->second * 100 / num << '\n';
	}
}