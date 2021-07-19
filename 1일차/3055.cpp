#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int r, c;
char map[51][51];
bool wvisit[51][51];
bool gvisit[51][51];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
queue <pair<pair<int, int>, int>> q;
queue <pair<pair<int, int>, int>> wq;
void waterMove(int t) {
	while (!wq.empty()) {
		int curx = wq.front().first.first;
		int cury = wq.front().first.second;
		int dis = wq.front().second;

		if (dis != t) return;

		wq.pop();

		for (int i = 0; i < 4; i++) {
			int tx = curx + dx[i];
			int ty = cury + dy[i];
			if (tx <= 0 || tx > r || ty <= 0 || ty > c) continue;
			if (wvisit[tx][ty]) continue;
			if (map[tx][ty] == 'X' || map[tx][ty] == 'D') continue;

			wq.push({ {tx,ty},dis + 1 });
			wvisit[tx][ty] = true;
			map[tx][ty] = '*';
		}
	}
}

void goMove(int t) {
	while (!q.empty()) {
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int dis = q.front().second;

		if (dis != t) return;

		q.pop();

		if (map[curx][cury] == 'D') {
			cout << dis;
			exit(0);
		}
		if (map[curx][cury] == '*') continue;

		for (int i = 0; i < 4; i++) {
			int tx = curx + dx[i];
			int ty = cury + dy[i];
			if (tx <= 0 || tx > r || ty <= 0 || ty > c) continue;
			if (gvisit[tx][ty]) continue;
			if (map[tx][ty] == 'X' || map[tx][ty] == '*') continue;

			q.push({ {tx,ty},dis + 1 });
			gvisit[tx][ty] = true;
		}
	}

	if (q.empty()) {
		cout << "KAKTUS";
		exit(0);
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push({ {i,j},0 });
				gvisit[i][j] = true;
			}

			else if (map[i][j] == '*') {
				wq.push({ { i,j },0 });
				wvisit[i][j] = true;
			}
		}
	}

	int t = 0;
	while (1) {
		goMove(t);
		waterMove(t);
		
		t++;
	}

}