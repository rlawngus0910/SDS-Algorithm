#include <iostream>
#include <stack>
using namespace std;
int n;
stack <int> st;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		string com;
		cin >> com;

		if (com == "push") {
			int x;
			cin >> x;
			st.push(x);
		}

		else if (com == "top") {
			if (st.empty()) cout << "-1" << '\n';
			else cout << st.top() << '\n';
		}

		else if (com == "size") {
			cout << st.size() << '\n';
		}

		else if (com == "pop") {
			if (st.empty()) cout << "-1" << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}

		else if (com == "empty") {
			if (st.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
	}
}