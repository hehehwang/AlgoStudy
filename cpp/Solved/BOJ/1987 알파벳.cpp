#include <bits/stdc++.h>
using namespace std;
// 1987 알파벳
#define FOR(i, n, m) for(int i=(n); i<m; i++)
using PII = pair<int, int>;

int chk[26];
string board[22];
stack<PII> Q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int R, C, ans;
void dfs(int vr, int vc, int cnt) {
	ans = max(cnt, ans);
	if (ans == 26) return;
	FOR(k, 0, 4) {
		int nr = vr + dr[k];
		int nc = vc + dc[k];
		if (nr < 0 || nc < 0 || R <= nr || C <= nc) continue;
		if (chk[board[nr][nc] - 'A']) continue;
		chk[board[nr][nc] - 'A'] = true;
		dfs(nr, nc, cnt + 1);
		chk[board[nr][nc] - 'A'] = false;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	FOR(i, 0, R) cin >> board[i];
	Q.push({ 0, 0 });
	chk[board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << ans;
}