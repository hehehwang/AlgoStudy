#include <bits/stdc++.h>
using namespace std;
// 2573 빙산
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int br, bc;
int board[302][302];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
void melt() {
	int tBoard[302][302] = {};

	FOR(i, 0, br) FOR(j, 0, bc) {
		if (!board[i][j]) continue;
		int cnt = 0;
		FOR(k, 0, 4) {
			int nr = i + dr[k];
			int nc = j + dc[k];
			if (nr < 0 || br <= nr || nc < 0 || bc <= nc) continue;
			if (!board[nr][nc]) cnt++;
		}
		tBoard[i][j] = max(board[i][j] - cnt, 0);
	}
	FOR(i, 0, br) FOR(j, 0, bc) board[i][j] = tBoard[i][j];
}

int iceberg() {
	int cnt = 0;
	int vis[302][302] = {};
	queue<pair<int, int>> Q = {};

	FOR(i, 0, br) FOR(j, 0, bc) {
		if (!board[i][j]) continue;
		if (vis[i][j]) continue;
		Q.push({ i, j });
		cnt++;
		while (!Q.empty()) {
			auto v = Q.front(); Q.pop();
			FOR(k, 0, 4) {
				int nr = v.first + dr[k];
				int nc = v.second + dc[k];
				if (nr < 0 || br <= nr || nc < 0 || bc <= nc) continue;
				if (vis[nr][nc]) continue;
				if (!board[nr][nc]) continue;
				Q.push({ nr, nc });
				vis[nr][nc] = 1;
			}
		}
	}
	return cnt;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> br >> bc;
	FOR(i, 0, br) FOR(j, 0, bc) cin >> board[i][j];
	int year = 0;
	while (1) {
		int ib = iceberg();
		if (ib >= 2) {
			cout << year;
			break;
		}
		if (ib == 0) {
			cout << 0;
			break;
		}
		year++;
		melt();
	}
}