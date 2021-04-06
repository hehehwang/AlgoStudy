#include <bits/stdc++.h>
using namespace std;
// 2178 미로 탐색

int h, w;
string board[102];
int vis[102][102];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int cnt;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> board[i];
		fill(vis[i], vis[i] + w, -1);
	}
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	vis[0][0] = 1;

	while (!Q.empty()) {
		pair <int, int> v = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = v.first + dy[dir];
			int nx = v.second + dx[dir];
			if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
			if (vis[ny][nx] != -1 || board[ny][nx] == '0') continue;
			vis[ny][nx] = vis[v.first][v.second] + 1;
			Q.push({ ny, nx });
		}

	}
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		cout << vis[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << vis[h-1][w-1];
}

