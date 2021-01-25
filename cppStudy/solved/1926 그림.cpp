#include <bits/stdc++.h>
using namespace std;
// 1926 그림

int field[502][502];
bool vis[502][502];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;
	for (int i=0; i < h; i++) {
		for (int j=0; j < w; j++) {
			cin >> field[i][j];
		}
	}
	int cnt = 0;
	int areaMax = 0;
	int areaTmp = 0;
	queue <pair<int, int>> Q = {};

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (field[i][j] == 1 && vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i, j });
				cnt += 1;
			}
			// if (!Q.empty()) cout << "Queue: " << Q.front().first << " " << Q.front().second << "\n";
			areaTmp = 0;
			while (!Q.empty()) {
				pair<int, int> v = Q.front();
				Q.pop();
				areaTmp ++;
				for (int dir = 0; dir < 4; dir++) {
					int ny = v.first + dy[dir];
					int nx = v.second + dx[dir];
					if (nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
					if (vis[ny][nx] || field[ny][nx] != 1) continue;
					vis[ny][nx] = 1;
					Q.push({ ny, nx });
					}
				}
			areaMax = max(areaTmp, areaMax);
			}
		}
	cout << cnt << "\n";
	cout << areaMax;
	}