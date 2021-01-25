#include <bits/stdc++.h>
using namespace std;
// 7576 토마토

int h, w;
int board[1002][1002];
int vis[1002][1002];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				Q.push({ i, j });
				vis[i][j] = 1;
			}
			else if (board[i][j] == 0) vis[i][j] = -1;
		}
	}

	while (!Q.empty()) {
		pair<int, int> v = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = v.first + dy[i];
			int nx = v.second + dx[i];
			if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
			if (vis[ny][nx] >= 0) continue;
			vis[ny][nx] = vis[v.first][v.second] + 1;
			Q.push({ ny, nx });
		}
	}
	bool F = true;
	int mxVis = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (vis[i][j] == -1) {
				F = false;
				break;
			}
			mxVis = max(mxVis, vis[i][j]);
		}
	}
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		cout << vis[i][j] << ' ';
	//	}
	//	cout << "\n";
	//}
	if (F) cout << mxVis - 1;
	else cout << -1;
}

