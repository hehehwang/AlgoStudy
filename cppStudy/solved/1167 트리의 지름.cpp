#include <bits/stdc++.h>
using namespace std;
// 1167 트리의 지름
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define node second
const int VLIM = 100002;
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
	FOR(i, 0, v) {
		int f;
		cin >> f;
		while (1){
			int t;
			cin >> t;
			if (t == -1) break;
			int c;
			cin >> c;
			adj[f].push_back({ c, t });
		}
	}
	vis[1] = true;
	dfs(1, 0);
	fill(vis, vis + VLIM, false);
	vis[mxNode] = true;
	dfs(mxNode, 0);
	cout << mxCost;
}