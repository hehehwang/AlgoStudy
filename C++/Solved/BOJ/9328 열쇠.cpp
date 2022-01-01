#include <bits/stdc++.h>
using namespace std;
// 9328 열쇠
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using PII = pair<int, int>;

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int TC;
	cin >> TC;
	FOR(i, 0, TC) {
		int bR, bC;
		char board[103][103] = {};
		bool keys[26] = {};
		int ans = 0;
		cin >> bR >> bC;
		FOR(i, 0, bR+2) fill(board[i], board[i] + bC+2, '.');
		FOR(i, 0, bR) {
			string sss;
			cin >> sss;
			FOR(j, 0, bC) {
				board[i+1][j+1] = sss[j];
			}
		}
		string startKey;
		cin >> startKey;
		if (startKey != "0") {
			for (char k : startKey) {
				keys[k - 'a'] = true;
			}
		}
		bool flag = true;
		while (flag) {
			flag = false;
			queue<PII> Q;
			bool vis[103][103] = {};
			vis[0][0] = true;
			Q.push({ 0, 0 });
			while (!Q.empty()) {
				PII v = Q.front(); Q.pop();
				FOR(k, 0, 4) {
					int nr = v.first + dr[k], nc = v.second + dc[k];
					if (nr < 0 || nc < 0 || bR+2 <= nr || bC+2 <= nc) continue;
					if (vis[nr][nc]) continue;
					char curr = board[nr][nc];
					if (curr == '*') continue;
					if (curr == '$') {
						ans++;
						flag = true;
						board[nr][nc] = '.';
					}
					if (curr != '.') {
						if (curr <= 'Z' && !keys[curr-'A']) continue;
						if ('a' <= curr) {
							keys[curr - 'a'] = true;
							flag = true;
						}
						board[nr][nc] = '.';
					}
					vis[nr][nc] = true;
					Q.push({ nr, nc });

				}
			}
		}
		cout << ans << '\n';
	}
}