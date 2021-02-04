#include <bits/stdc++.h>
using namespace std;
// 1600 말이 되고픈 원숭이
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int board[202][202];
int vis[32][202][202];
int dmr[4] = { 0, 0, 1, -1 };
int dmc[4] = { 1, -1, 0, 0 };
int dkr[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dkc[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
queue<tuple<int, int, int>> Q;
int bR, bC, Kn;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Kn >> bC >> bR;
	FOR(i, 0, bR) FOR(j, 0, bC) cin >> board[i][j];
	Q.push({ 0, 0, 0});
	vis[0][0][0] = 1;
	while (!Q.empty()) {
		auto v = Q.front(); 
		Q.pop();
		int vk = get<0>(v), vr = get<1>(v), vc = get<2>(v);
		if (vk < Kn) {
			FOR(i, 0, 8) {
				int nr = vr + dkr[i], nc = vc + dkc[i];
				if (nr < 0 || nc < 0 || bR <= nr || bC <= nc) continue;
				if (board[nr][nc]) continue;
				if (vis[vk + 1][nr][nc]) continue;
				vis[vk + 1][nr][nc] = vis[vk][vr][vc] + 1;
				Q.push({ vk + 1, nr, nc });
			}
		}
		FOR(i, 0, 4) {
			int nr = vr + dmr[i], nc = vc + dmc[i];
			if (nr < 0 || nc < 0 || bR <= nr || bC <= nc) continue;
			if (board[nr][nc]) continue;
			if (vis[vk][nr][nc]) continue;
			vis[vk][nr][nc] = vis[vk][vr][vc] + 1;
			Q.push({ vk, nr, nc });
		}
	}
	vector<int> res;
	int ans = 0x7f7f7f7f;
	FOR(i, 0, Kn+1) res.push_back(vis[i][bR - 1][bC - 1]);
	for (auto r : res) if(r) ans = min(ans, r); 
	//FOR(k, 0, Kn+1) {
	//	FOR(i, 0, bR) {
	//		FOR(j, 0, bC) {
	//			cout << vis[k][i][j] << ' ';
	//		}
	//		cout << '\n';
	//	}
	//	cout << '\n';
	//}
	if (ans != 0x7f7f7f7f) cout << ans-1;
	else cout << -1;
}