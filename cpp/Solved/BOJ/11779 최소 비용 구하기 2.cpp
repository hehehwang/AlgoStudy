#include <bits/stdc++.h>
using namespace std;
// 11779 최소비용 구하기 2
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define vert second
using PII = pair<int, int>;
constexpr int INF = 100000002;
constexpr int VLIM = 1002;

// vector<PII> adj[VLIM];
int adj[VLIM][VLIM];
priority_queue<PII, vector<PII>, greater<PII>> pQ;
int minCost[VLIM];
int route[VLIM];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, F, T;
	cin >> V >> E;
	FOR(i, 0, V + 1) fill(adj[i], adj[i] + V + 1, INF);
	FOR(i, 0, E) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}
	cin >> F >> T;
	fill(minCost, minCost + V + 1, INF);
	minCost[F] = 0;
	pQ.push({ 0, F });
	while (!pQ.empty()) {
		int vv, vc;
		tie(vc, vv) = pQ.top(); pQ.pop();
		if (vc != minCost[vv]) continue;
		FOR(nv, 0, V+1) {
			if (adj[vv][nv] == INF) continue;
			int nc = vc + adj[vv][nv];
			if (minCost[nv] <= nc) continue; // nc가 minCost와 같은 경우를 거르지 않으면 전 노선의 cost가 0일 경우에 무한루프를 돌게 된다.
			minCost[nv] = nc;
			route[nv] = vv;
			pQ.push({ nc, nv });
		}
	}
	cout << minCost[T] << '\n';
	vector<int> enRoute = { T };
	while (enRoute.back() != F) {
		enRoute.push_back(route[enRoute.back()]);
	}
	cout << enRoute.size() << '\n';
	for (auto i = enRoute.rbegin(); i != enRoute.rend(); i++) {
		cout << *i << ' ';
	}
}