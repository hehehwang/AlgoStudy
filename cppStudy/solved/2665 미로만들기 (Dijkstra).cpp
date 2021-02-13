#include <bits/stdc++.h>
using namespace std;
// 2665 미로 만들기 (Dijkstra)
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define vert second
using TI3 = tuple<int, int, int>;
constexpr int INF = 100000002;
constexpr int NLIM = 52;

string board[NLIM];
priority_queue<TI3, vector<TI3>, greater<TI3>> pQ;
int minCost[NLIM][NLIM];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	FOR(i, 0, N) cin >> board[i];
	FOR(i, 0, N) fill(minCost[i], minCost[i] + NLIM, INF);
	pQ.push({ 0, 0, 0 });
	minCost[0][0] = 0;

	while (!pQ.empty()) {
		auto v = pQ.top(); pQ.pop();
		int vcost, vr, vc;
		tie(vcost, vr, vc) = v;
		if (vcost != minCost[vr][vc]) continue;
		FOR(k, 0, 4) {
			int nr = vr + dr[k];
			int nc = vc + dc[k];
			if (nr < 0 || nc < 0 || N <= nr || N <= nc) continue;
			int newCost = vcost + 49 - int(board[nr][nc]);
			if (minCost[nr][nc] <= newCost) continue;
			minCost[nr][nc] = newCost;
			pQ.push({ newCost, nr, nc });
		}
	}
	cout << minCost[N - 1][N - 1];
}