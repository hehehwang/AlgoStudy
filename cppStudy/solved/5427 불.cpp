#include <bits/stdc++.h>
using namespace std;
// 5427 불
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define R first
#define C second

int tc, br, bc;
int board[1002][1002] = {};
int visF[1002][1002] = {};
int visS[1002][1002] = {};
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tc;
	FOR(ttt, 0, tc) {
		FOR(i, 0, 1002) {
			fill(visF[i], visF[i] + 1002, 0);
			fill(visS[i], visS[i] + 1002, 0);
		}
		bool escape = false;
		queue<pair<int, int>> Qf = {}, Qs = {};

		cin >> bc >> br;
		FOR(i, 0, br) FOR(j, 0, bc) {
			char c;
			cin >> c;
			if (c == '#') board[i][j] = -1;
			else {
				if (c == '@') {
					Qs.push({ i, j });
					visS[i][j] = 1;
				}
				else if (c == '*') { 
					Qf.push({ i, j });
					visF[i][j] = 1;
				}
				board[i][j] = 0;
			}
		}
		while (!Qf.empty()) {
			auto v = Qf.front(); Qf.pop();
			FOR(i, 0, 4) {
				int nr = v.R + dr[i];
				int nc = v.C + dc[i];
				if (nr < 0 || br <= nr || nc < 0 || bc <= nc) continue;
				if (board[nr][nc] == -1) continue;
				if (visF[nr][nc]) continue;
				visF[nr][nc] = visF[v.R][v.C] + 1;
				Qf.push({ nr, nc });
			}
		}
		while ((!Qs.empty())&& (!escape)) {
			auto v = Qs.front(); Qs.pop();
			FOR(i, 0, 4) {
				int nr = v.R + dr[i];
				int nc = v.C + dc[i];
				if (nr < 0 || br <= nr || nc < 0 || bc <= nc) {
					cout << visS[v.R][v.C] << '\n';
					escape = true;
					break;
				}
				if (board[nr][nc] == -1) continue;
				if (visS[nr][nc]) continue;
				if (visF[nr][nc] != 0 && visF[nr][nc] <= visS[v.R][v.C] + 1) continue;
				visS[nr][nc] = visS[v.R][v.C] + 1;
				Qs.push({ nr, nc });
			}
		}
		if (!escape) cout << "IMPOSSIBLE" << '\n';
	}
}