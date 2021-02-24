#include <bits/stdc++.h>
using namespace std;
// 1516 게임 개발
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

const int MXN = 502;
int N;
int cost[MXN];
int dp[MXN];
int inDeg[MXN];
vector<int> before[MXN];
vector<int> after[MXN];
queue<int> noIn;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	FOR(i, 1, N+1) {
		int a;
		cin >> a;
		cost[i] = a;
		while (1) {
			cin >> a;
			if (a == -1) break;
			before[i].push_back(a);
			inDeg[i]++;
			after[a].push_back(i);
		}
		if (before[i].empty()) noIn.push(i);
	}
	while (!noIn.empty()) {
		auto v = noIn.front(); noIn.pop();
		int tmp = 0;
		for (auto nv : before[v]) tmp = max(tmp, dp[nv]);
		dp[v] = tmp + cost[v];
		for (auto nv : after[v]) {
			inDeg[nv] --;
			if (!inDeg[nv]) noIn.push(nv);
		}
	}
	FOR(i, 1, N + 1) cout << dp[i] << '\n';
}