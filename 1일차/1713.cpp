#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
vector <pair<int, pair<int, int>>> v;
bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.second.first == b.second.first)
		return a.second.second < b.second.second;
	
	else
		return a.second.first < b.second.first;

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0,x; i < m; i++) {
		bool check = false;
		cin >> x;

		for (int j = 0; j < v.size(); j++) {
			if (v[j].first == x) {
				v[j].second.first++;
				check = true;
				break;
			}
		}

		if (!check) {
			if (v.size() < n) {
				v.push_back({ x,{0,i} });
			}
			else {
				sort(v.begin(), v.end(), cmp);
				v.erase(v.begin());
				v.push_back({ x,{0,i} });
			}
		}
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';

}