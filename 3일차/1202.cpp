#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int >;
int n, k;
long long ans;
vector <pii> jew;
vector <int> bag;
priority_queue <int, vector<int>> pq;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0,m,c; i < n; i++) {
		cin >> m >> c;
		jew.push_back({ m,c });
	}

	for (int i = 0, x; i < k; i++) {
		cin >> x;
		bag.push_back(x);
	}

	sort(jew.begin(), jew.end());
	sort(bag.begin(), bag.end());

	int jewIdx = 0;
	for (int i = 0; i < bag.size(); i++) {
		int bagSize = bag[i];

		while (1) {
			if (jewIdx < jew.size() && bagSize >= jew[jewIdx].first) {
				pq.push(jew[jewIdx].second);
				jewIdx++;
			}
			else break;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;
}