#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int, int, int>;
// 1922 네트워크 연결
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

priority_queue<ti3, vector<ti3>, greater<ti3>> pQ; /// {cost, from, to}
vector<bool> chk(1002, false);
vector<pair<int, int>> adj[1002]; // {cost, index}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e;
	cin >> v;
	cin >> e;
	FOR(i, 0, e) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b) continue;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	for (auto edge : adj[1]) pQ.push({ edge.first, 1, edge.second });
	chk[1] = true;
	int ans = 0;
	int nodeIn = 1;
	while (1) {
		int c, a, b;
		tie(c, a, b) = pQ.top(); pQ.pop();
		if (chk[b]) continue;
		chk[b] = true;
		ans += c;
		nodeIn++;
		if (nodeIn == v) break;
		for (auto edge : adj[b]) { 
			if (chk[edge.second]) continue;
			pQ.push({ edge.first, b, edge.second }); 
		}
	}
	cout << ans;
}