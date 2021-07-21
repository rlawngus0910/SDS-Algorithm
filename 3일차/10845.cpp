#include <iostream>
#include <queue>
using namespace std;
int n;
queue <int> q;
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
			q.push(x);
		}

		else if (com == "front") {
			if (q.empty()) cout << "-1" << '\n';
			else cout << q.front() << '\n';
		}

		else if (com == "back") {
			if (q.empty()) cout << "-1" << '\n';
			else cout << q.back() << '\n';
		}

		else if (com == "size") {
			cout << q.size() << '\n';
		}

		else if (com == "pop") {
			if (q.empty()) cout << "-1" << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}

		else if (com == "empty") {
			if (q.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
	}
}