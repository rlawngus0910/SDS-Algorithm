#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue <int, vector<int>> pq;
priority_queue <int, vector<int>, greater<>> q;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int num;
		cin >> num;

		if (pq.size() == q.size()) {
			if (!q.empty() && num > q.top()) {
				pq.push(q.top());
				q.pop();
				q.push(num);
				
			}

			else {
				pq.push(num);
			}
			
		}

		else if (q.size() + 1 == pq.size()) {
			if (pq.top() > num) {
				q.push(pq.top());
				pq.pop();
				pq.push(num);
			}
			else {
				q.push(num);
			}
		}


		cout << pq.top() << '\n';
	}

}