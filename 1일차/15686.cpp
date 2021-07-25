#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int n, m, homeCnt;
int map[51][51];

bool check[13];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
vector <pair<int, int>> chi;

int ans = 1e9;
int bfs(int cnt) {
	int temp = 0;
	bool visit[51][51] = { false, };
	queue <pair<pair<int, int>, int>> q;
	for (int i = 0; i < chi.size(); i++) {
		if (check[i]) {
			visit[chi[i].first][chi[i].second] = true;
			q.push({ {chi[i].first, chi[i].second}, 0 });
		}
	}
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int dist = q.front().second;

		q.pop();

		if (map[curx][cury] == 1) {
			cnt--;
			temp += dist;
		}

		if (cnt == 0) break;

		for (int i = 0; i < 4; i++) {
			int tx = curx + dx[i];
			int ty = cury + dy[i];

			if (tx <= 0 || tx > n || ty <= 0 || ty > n) continue;
			if (visit[tx][ty]) continue;
			visit[tx][ty] = true;
			q.push({ {tx,ty}, dist + 1 });
		}
	}

	memset(visit, false, sizeof(visit));
	return temp;
}
void go(int idx, int cnt) {

	if (cnt == m) {
		ans = min(ans,bfs(homeCnt));
		return;
	}


	for (int i = idx + 1; i < chi.size(); i++) {
		

		if (!check[i]) {
			check[i] = true;
			go(i, cnt + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) homeCnt++;
			if (map[i][j] == 2)
				chi.push_back({ i,j });
		}
	}

	go(-1, 0);

	cout << ans;
	
}