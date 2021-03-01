#include <bits/stdc++.h>
using namespace std;
// 15681 트리와 쿼리
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
const int mxN = 10e5 + 2;
int N, R, Q;
vector<int> adj[mxN];
vector<bool> vis(mxN, 0);
int dp[mxN];
int cnt;
int dpdp(int n) {
	vis[n] = true;
	cnt++;
	int rtn = 1;
	for (auto v : adj[n]) {
		if (vis[v]) continue;
		rtn += dpdp(v);
	}
	dp[n] = rtn;
	return dp[n];
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> R >> Q;
	FOR(i, 0, N-1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dpdp(R);
	FOR(i, 0, Q) {
		int q;
		cin >> q;
		cout << dp[q] << '\n';
	}
	//cout << cnt;
}