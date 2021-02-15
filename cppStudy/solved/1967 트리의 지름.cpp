#include <bits/stdc++.h>
using namespace std;
// 1967 트리의 지름
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define node second
const int VLIM = 10002;
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

vector<PII> adj[VLIM];
bool vis[VLIM];
int mxCost, mxNode;
void dfs(int v, int c) {
	if (mxCost < c) {
		mxNode = v;
		mxCost = c;
	}
	for (auto nv : adj[v]) {
		if (vis[nv.node]) continue;
		vis[nv.node] = true;
		dfs(nv.node, c + nv.cost);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;
	FOR(i, 0, v - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	vis[1] = true;
	dfs(1, 0);
	fill(vis, vis + VLIM, false);
	vis[mxNode] = true;
	dfs(mxNode, 0);
	cout << mxCost;
}