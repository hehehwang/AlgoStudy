#include <bits/stdc++.h>
using namespace std;
// 2579 계단
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int sN;
int stair[302];
int dp[303][2];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> sN;
	FOR(i, 0, sN) cin >> stair[i];
	dp[1][0] = stair[0];
	FOR(i, 2, sN + 1) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i - 1];
		dp[i][1] = dp[i - 1][0] + stair[i - 1];
	}
	cout << max(dp[sN][0], dp[sN][1]);
}