#include <bits/stdc++.h>
using namespace std;
// 2146 다리만들기
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define R first
#define C second

int bN;
int board[102][102];
int vis[102][102];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
deque<pair<int, int>> Q;
vector<deque<pair<int, int>>> islQ;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int islN = 0;
	cin >> bN;
	FOR(i, 0, bN) FOR(j, 0, bN) cin >> board[i][j];
	FOR(i, 0, bN) FOR(j, 0, bN) {
		if (vis[i][j]) continue;
		if (!board[i][j]) continue;
		deque<pair<int, int>> tQ = {};
		islN++;
		Q.push_back({ i, j });
		tQ.push_back({ i, j });
		vis[i][j] = 1;
		board[i][j] = islN;
		while (!Q.empty()) {
			auto v = Q.front(); Q.pop_front();
			FOR(k, 0, 4) {
				auto nr = v.R + dr[k];
				auto nc = v.C + dc[k];
				if (nr < 0 || nc < 0 || bN <= nr || bN <= nc) continue;
				if (vis[nr][nc]) continue;
				if (!board[nr][nc]) continue;
				Q.push_back({ nr, nc });
				tQ.push_back({ nr, nc });
				vis[nr][nc] = 1;
				board[nr][nc] = islN;
			}
		}
		islQ.push_back(tQ);
	}
	int bridgeN = 1000;
	FOR(isli, 1, islN + 1) {
		FOR(i, 0, bN) fill(vis[i], vis[i] + bN, 0);
		int bl = 0;
		deque<pair<int, int>> tQ = islQ[isli - 1];
		for (auto coord : tQ) vis[coord.R][coord.C] = 1;
		while (!tQ.empty() && !bl) {
			auto v = tQ.front(); tQ.pop_front();
			FOR(k, 0, 4) {
				auto nr = v.R + dr[k];
				auto nc = v.C + dc[k];
				if (nr < 0 || nc < 0 || bN <= nr || bN <= nc) continue;
				if (vis[nr][nc]) continue;
				if (board[nr][nc] == 0)	vis[nr][nc] = vis[v.R][v.C] + 1; // 바다 위
				else if (board[nr][nc] != isli) { // 다음 섬 찾음
					bl = vis[v.R][v.C];
					break;
				}
				else vis[nr][nc] = 1;
				tQ.push_back({ nr, nc });
			}
		}
		bridgeN = min(bridgeN, bl);
	}
	cout << bridgeN-1;
}