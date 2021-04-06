#include <bits/stdc++.h>
using namespace std;
// 3197 백조의 호수
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int board[1502][1502];
int vis[1502][1502];
int bR, bC;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
queue<pair<int, int>> Q;
vector<pair<int, int>> goni;
void melt() {
	FOR(i, 0, bR) fill(vis[i], vis[i] + bC, 0);
	FOR(i, 0, bR) FOR(j, 0, bC) {
		if (!board[i][j]) continue;
		bool doMelt = false;
		FOR(k, 0, 4) {
			int nr = i + dr[k];
			int nc = j + dc[k];
			if (nr < 0 || nc < 0 || bR <= nr || bC <= nc) continue;
			if (board[nr][nc]) continue;
			doMelt = true;
			break;
		}
		if (!doMelt) vis[i][j] = 1;
	}
	FOR(i, 0, bR) FOR(j, 0, bC) board[i][j] = vis[i][j];
}
bool goniConnect() {
	FOR(i, 0, bR) fill(vis[i], vis[i] + bC, 0);
	Q.push(goni[0]);
	vis[goni[0].first][goni[0].second] = 1;
	while (!Q.empty()) {
		auto v = Q.front(); Q.pop();
		int vr = v.first, vc = v.second;
		FOR(i, 0, 4) {
			int nr = vr + dr[i], nc = vc + dc[i];
			if (nr < 0 || nc < 0 || bR <= nr || bC <= nc) continue;
			if (board[nr][nc]) continue;
			if (vis[nr][nc]) continue;
			if (nr == goni[1].first && nc == goni[1].second) return true;
			Q.push({ nr, nc });
			vis[nr][nc] = 1;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> bR >> bC;
	FOR(i, 0, bR) FOR(j, 0, bC) {
		char c;
		cin >> c;
		if (c == '.') board[i][j] = 0;
		else if (c == 'X') board[i][j] = 1;
		else {
			board[i][j] = 0;
			goni.push_back({ i, j });
		}
	}
	int cnt = 0;
	while (!goniConnect()) {
		melt();
		cnt++;
	}
	cout << cnt;

	//FOR(i, 0, 5) {
	//	cout << i << '\n';
	//	FOR(i, 0, bR) {
	//		FOR(j, 0, bC) {
	//			cout << board[i][j] << ' ';
	//		}
	//		cout << '\n';
	//	}
	//	cout << '\n';
	//	melt();
	//}
}