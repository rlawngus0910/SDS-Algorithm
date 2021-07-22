#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
vector<int> v[14];
bool visit[14];
map <int, int> m;
int x, y;
bool bfs(int start) {
	queue<int> q;
	visit[start] = true;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int tx = v[cur][i];
			if (visit[tx]) return false;
			visit[tx] = true;
			q.push(tx);
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (!visit[iter->first]) return false;
	}

	return true;

}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int k = 1;
	while (1) {
		
		
		cin >> x >> y;
		if (x == -1 && y == -1) return 0;

		if (x == 0 && y == 0) {
			bool check = true;
			bool isMap = false;
			int cnt = 0;
			int start = 0;
			for (auto iter = m.begin(); iter != m.end(); iter++) {
				isMap = true;
				//cout << iter->first << ' ' << iter->second << '\n';
				if (iter->second > 1) {
					check = false;
					break;
				}
				if (iter->second == 0) {
					cnt++;
					start = iter->first;
				}

				if (cnt == 2) {
					check = false;
					break;
				}
			}

			if (!check) {
				cout << "Case " << k++ << " is not a tree.\n";
				
			}

			else if (!isMap) {
				cout << "Case " << k++ << " is a tree.\n";
			}

			else if (bfs(start)) {
				cout << "Case " << k++ << " is a tree.\n";
			
			}

			else {
				cout << "Case " << k++ << " is not a tree.\n";
				
			}
			for (int i = 0; i < 13; i++) v[i].clear();
			memset(visit, false, sizeof(visit));
			m.clear();
			continue;
			
		}

		v[x].push_back(y);
		if (m[x] == 0) {
			m[x] = 0;
		}
		m[y]++;

	}
}