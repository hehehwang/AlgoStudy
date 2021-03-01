#include <bits/stdc++.h>
using namespace std;
// 1976 여행 가자 [UnionFind]
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int grpNo[202];
int adj[202][202];
int find(int v) {
	if (grpNo[v] == v) return v;
	grpNo[v] = find(grpNo[v]);
	return grpNo[v];
}
void unite(int a, int b) {
	if (a < b) swap(a, b);
	grpNo[find(a)] = find(b);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N + 1) {
		grpNo[i] = i;
		FOR(j, 1, N + 1) cin >> adj[i][j];
	}
	FOR(i, 1, N+1) {
		FOR(j, 1, N+1) {
			if (!adj[i][j]) continue;
			unite(i, j);
		}
	}
	vector<int> travelPlan(M, 0);
	FOR(i, 0, M) cin >> travelPlan[i];
	int tmp = find(travelPlan[0]);
	for (auto v : travelPlan) {
		if (tmp != find(v)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}