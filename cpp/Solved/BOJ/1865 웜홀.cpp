#include <bits/stdc++.h>
using namespace std;
// 1865 웜홀
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define cost first
#define node second
const int VLIM = 502;
const int INF = 1000000007;
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

int V, R, W, a, b, c;
bool minusLoop(vector<PII> adj[]) {
	vector<int> upper(V+1, INF);
	bool updated = false;
    upper[1] = 0;
	FOR(i, 0, V) {
		updated = false;
		FOR(v, 1, V+1) {
			for (auto nv : adj[v]) {
				if (upper[v] + nv.cost < upper[nv.node]) {
					updated = true;
					upper[nv.node] = upper[v] + nv.cost;
				}
			}
		}
		if (!updated) break;
	}
	return updated;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	FOR(ttt, 0, tc) {
		vector<PII> adj[VLIM] = {};
		
		cin >> V >> R >> W;
		FOR(i, 0, R) {
			cin >> a >> b >> c;
			adj[a].push_back({ c, b });
			adj[b].push_back({ c, a });
		}
		FOR(i, 0, W) {
			cin >> a >> b >> c;
			adj[a].push_back({ -c, b });
		}
		if (minusLoop(adj)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}