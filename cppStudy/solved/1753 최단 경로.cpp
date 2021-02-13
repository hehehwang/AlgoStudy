#include <bits/stdc++.h>
using namespace std;
// 1753 최단 경로
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define vert second
using PII = pair<int, int>;
constexpr int INF = 0x7f7f7f7f;
constexpr int VLIM = 20002;

priority_queue<PII, vector<PII>, greater<PII>> pQ; // cost, vertex
vector<PII> adj[VLIM];
int minDist[VLIM];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	FOR(i, 0, E) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	fill(minDist, minDist + VLIM, INF);
	minDist[K] = 0;
	pQ.push({ 0, K });
	while (!pQ.empty()) {
		auto v = pQ.top(); pQ.pop();
		if (v.cost != minDist[v.vert]) continue;
		for (auto nv : adj[v.vert]) {
			if (minDist[nv.vert] < nv.cost + v.cost) continue;
			minDist[nv.vert] = nv.cost + v.cost;
			pQ.push({ nv.cost + v.cost, nv.vert });
		}
	}
	FOR(i, 1, V+1) {
		if (minDist[i] != INF) cout << minDist[i];
		else cout << "INF";
		cout << '\n';
	}
}