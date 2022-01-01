#include <bits/stdc++.h>
using namespace std;
// 2098 외판원 순회
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int adj[17][17];
int dp[1 << 16][17];
int N;
int cnt;
queue<pair<int, int>> Q;
/* DFS, TL
void TSP(int vis, int city) {
	cnt++;
	FOR(nc, 0, N) {
		if (!adj[city][nc]) continue;
		if (vis & 1 << nc) continue;
		int newVis = vis | 1 << nc;
		if (newVis != (1 << N) - 1 && nc == 0) continue;
		if (dp[newVis][nc]) dp[newVis][nc] = min(dp[newVis][nc], dp[vis][city] + adj[city][nc]);
		else dp[newVis][nc] = dp[vis][city] + adj[city][nc];
		TSP(vis | 1 << nc, nc);
	}
}
*/
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[1][0] = 0;
	cin >> N;
	FOR(i, 0, N) FOR(j, 0, N) cin >> adj[i][j];
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		int vis, city;
		tie(vis, city) = Q.front(); Q.pop();
		cnt++;
		FOR(newCity, 0, N) {
			if (!adj[city][newCity]) continue;
			if (vis & 1 << newCity) continue;
			int newVis = vis | 1 << newCity;
			if (newVis != (1 << N) - 1 && newCity == 0) continue;
			if (dp[newVis][newCity]) {
				dp[newVis][newCity] = min(dp[newVis][newCity], dp[vis][city] + adj[city][newCity]);
			}
			else {
				dp[newVis][newCity] = dp[vis][city] + adj[city][newCity];
				Q.push({ newVis, newCity });
			}
		}
	}
	// TSP(0, 0);
	// cout << cnt << '\n';
	cout << dp[(1 << N) - 1][0];
}