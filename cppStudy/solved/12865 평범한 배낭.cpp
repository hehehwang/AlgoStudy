#include <bits/stdc++.h>
using namespace std;
// 12865 평범한 배낭
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

int dp[102][100002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, lim;
	cin >> n >> lim;
	FOR(i, 0, n) {
		int w, v;
		cin >> w >> v;
		FOR(j, 0, max(w, lim)) dp[i + 1][j] = dp[i][j];
		FOR(j, 0, lim - w + 1) dp[i + 1][w + j] = max(dp[i][j] + v, dp[i][w + j]);
	}
	cout << dp[n][lim];
}