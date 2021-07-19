#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector <pair<string, long long>> v;
stack <long long> st;
int input[10001];
int n;

void clear() {
	while (!st.empty()) {
		st.pop();
	}
}

bool DUP() {
	if (st.empty()) {
		return false;
	}

	st.push(st.top());
	return true;
}

bool POP() {
	if (st.empty()) {
		return false;
	}

	st.pop();
	return true;
}

bool INV() {
	if (st.empty()) {
		return false;
	}

	long long num = st.top();
	st.pop();

	st.push(-num);
	return true;
}

void NUM(long long x) {
	st.push(x);
}

bool SWP() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
	long long second = st.top();
	st.pop();
	st.push(first);
	st.push(second);
	return true;
}

bool ADD() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
	long long second = st.top();
	st.pop();
	long long result = first + second;

	if (abs(result) > 1e9) return false;

	st.push(result);
	return true;
}

bool SUB() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
	long long second = st.top();
	st.pop();
	long long result = second - first;

	if (abs(result) > 1e9) return false;

	st.push(result);
	return true;
}

bool MUL() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
    long long second = st.top();
	st.pop();
	long long result = first * second;

	if (abs(result) > 1e9) return false;

	st.push(result);
	return true;
}

bool DIV() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
	long long second = st.top();
	st.pop();

	if (first == 0) return false;

	long long result = second / first;

	if (abs(result) > 1e9) return false;
	
	st.push(result);
	
	return true;
}

bool MOD() {
	if (st.size() < 2) {
		return false;
	}

	long long first = st.top();
	st.pop();
	long long second = st.top();
	st.pop();

	if (first == 0) return false;
	long long result = second % first;
	if (abs(result) > 1e9) return false;
	
	st.push(result);
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		v.clear();
		while (1) {
			string s;
			long long x;
			cin >> s;

			if (s == "QUIT") exit(0);
			if (s == "END") break;
			if (s == "NUM") cin >> x;
			else x = 0;

			v.push_back({ s, x });
		}

		cin >> n;

		for (int j = 0; j < n; j++) {
			bool check = true;
			cin >> input[j];
			st.push(input[j]);
			for (int i = 0; i < v.size(); i++) {
				string com = v[i].first;
				long long num = v[i].second;

				if (com == "DUP") {
					if (!DUP()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "POP") {
					if (!POP()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "INV") {
					if (!INV()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "NUM") {
					NUM(num);
				}

				if (com == "SWP") {
					if (!SWP()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "ADD") {
					if (!ADD()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "SUB") {
					if (!SUB()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "MUL") {
					if (!MUL()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "DIV") {
					if (!DIV()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

				if (com == "MOD") {
					if (!MOD()) {
						check = false;
						cout << "ERROR\n";
						break;
					}
				}

			}
			if (check) {
				if (st.size() != 1) cout << "ERROR\n";
				else cout << st.top() << '\n';
			}
			clear();
		}
		cout << '\n';
	}
}