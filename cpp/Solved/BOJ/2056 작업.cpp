#include <bits/stdc++.h>
using namespace std;
// 2056 작업
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;
const int LIM = 10002;

vector<int> pre[LIM];
vector<int> pro[LIM];
int cost[LIM];
int inDeg[LIM];
int dp[LIM];
queue<int> noIn;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	FOR(proReq, 1, N + 1) {
		int c, m;
		cin >> c >> m;
		if (!m) noIn.push(proReq);
		cost[proReq] = c;
		FOR(j, 0, m) {
			int preReq;
			cin >> preReq;
			pro[preReq].push_back(proReq);
			pre[proReq].push_back(preReq);
			inDeg[proReq]++;
		}
	}
	while (!noIn.empty()) {
		auto v = noIn.front(); noIn.pop();
		for (auto ov : pre[v]) dp[v] = max(dp[v], dp[ov]);
		dp[v] += cost[v];
		for (auto nv : pro[v]) {
			inDeg[nv] --;
			if (!inDeg[nv]) noIn.push(nv);
		}
	}
	cout << *max_element(dp, dp+N+1);
}