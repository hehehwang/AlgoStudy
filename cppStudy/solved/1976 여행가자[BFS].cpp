#include <bits/stdc++.h>
using namespace std;
// 1976 여행 가자 [BFS]
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int adj[202][202];
bool vis[202];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N+1) {
		FOR(j, 1, N+1) {
			cin >> adj[i][j];
		}
	}
	queue<int> Q;
	vector<int> toTravel(M, 0);
	FOR(i, 0, M) cin >> toTravel[i];
	Q.push(toTravel[0]);
	vis[toTravel[0]] = true;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		FOR(i, 1, N+1) {
			if (vis[i]) continue;
			if (!adj[v][i]) continue;
			vis[i] = true;
			Q.push(i);
		}
	}
	for (auto v : toTravel) {
		if (vis[v]) continue;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}