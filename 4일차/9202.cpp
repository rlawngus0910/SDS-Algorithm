#include <iostream>
using namespace std;
int w, b;
int findNum,maxLen;
int maxscore, score;
int maxFindNum;
string maxLenStr;
char grid[5][5];
bool visit[5][5];
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int LenToScore(int x) {
	if (x == 1 || x == 2) return 0;
	if (x == 3 || x == 4) return 1;
	if (x == 5) return 2;
	if (x == 6) return 3;
	if (x == 7) return 5;
	if (x == 8) return 11;
}
struct TrieNode {
	TrieNode* children[26];
	bool isEnd;
	bool isHit;

	TrieNode() {
		isEnd = false;
		isHit = false;
		for (int i = 0; i < 26; i++) children[i] = NULL;
	}

	void clearHit() {
		for (int i = 0; i < 26; i++) {
			if (children[i] != NULL) {
				children[i]->isHit = false;
				children[i]->clearHit();
			}
		}
	}


	void insert(string& key, int idx) {
		if (idx == key.length())
			isEnd = true;

		else {
			int nextIdx = key[idx] - 'A';
			if (children[nextIdx] == NULL)
				children[nextIdx] = new TrieNode();

			children[nextIdx]->insert(key, idx + 1);
		}
	}

	bool findFIrst(char ch) {
		int idx = ch - 'A';
		if (children[idx] == NULL) return false;
		else return true;
	}

	void find(int x,int y, int cnt, string s) {
		if (isEnd && !isHit) {
			findNum++;
			if (maxLen < cnt) {
				maxLen = cnt;
				maxLenStr = s;
			}

			else if (maxLen == cnt) {
				maxLenStr = min(maxLenStr, s);
			}
			
			score += LenToScore(cnt);
			isHit = true;
		}

		for (int i = 0,tx,ty; i < 8; i++) {
			tx = x + dx[i];
			ty = y + dy[i];

			if (tx <= 0 || tx > 4 || ty <= 0 || ty > 4) continue;
			if (visit[tx][ty]) continue;

			int nextIdx = grid[tx][ty] - 'A';
			if (children[nextIdx] == NULL) continue;
			
			visit[tx][ty] = true;
			children[nextIdx]->find(tx, ty, cnt + 1, s + grid[tx][ty]);
			visit[tx][ty] = false;
		}
	}
};



int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	TrieNode* root = new TrieNode();
	cin >> w;

	for (int i = 0; i < w; i++) {
		string s;
		cin >> s;
		root->insert(s, 0);
	}

	cin >> b;
	while (b--) {
		findNum = 0;
		maxFindNum = 0;
		maxLenStr = "";
		maxLen = 0;
		maxscore = 0;
		score = 0;
	
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				cin >> grid[i][j];
			}
		}

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				
				if (root->findFIrst(grid[i][j])) {
					string temp = "";
					temp += grid[i][j];
					visit[i][j] = true;
					root->children[grid[i][j]-'A']->find(i, j, 1, temp);
					visit[i][j] = false;
				}
				maxFindNum = max(findNum, maxFindNum);
				maxscore = max(score, maxscore);
			}
		}
		root->clearHit();
		cout << maxscore <<' ' <<maxLenStr << ' ' << findNum << '\n';
	}
}