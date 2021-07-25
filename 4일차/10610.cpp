#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int sum = 0;

	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}

	if (sum % 3 != 0) {
		cout << "-1";
		return 0;
	}

	sort(s.rbegin(), s.rend());
	
	if (s[s.length() - 1] == '0') cout << s;
	else cout << "-1";

}