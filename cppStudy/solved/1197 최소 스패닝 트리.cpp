#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 1197 최소 스패닝 트리
#define FOR(i, n, m) for(ll i=(n); i<(m); i++)

vector<int> adj[10002];
int grpNo[10002];
vector<tuple<int, int, int>> edge;
int find(int v) {
	if (grpNo[v] == v) return v;
	grpNo[v] = find(grpNo[v]);
	return grpNo[v];
}
void unite(int v1, int v2) {
	if (v2 < v1) swap(v1, v2);
	grpNo[find(v2)] = find(v1);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;
	FOR(i, 0, e) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(tie(c, a, b));
	}
	FOR(i, 0, v) grpNo[i] = i;
	sort(edge.begin(), edge.end());
	long long TotalCost = 0;
	for (auto ne : edge) {
		int cost = get<0>(ne), a = get<1>(ne), b = get<2>(ne);
		if (find(a) != find(b)) {
			TotalCost += cost;
			unite(a, b);
		}
	}
	cout << TotalCost;
}