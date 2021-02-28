#include <bits/stdc++.h>
using namespace std;
// 1149 RGB 거리
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second

int N;
int rC[1002][3]; // rgbCost
int dp[1002][3];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	FOR(i, 0, N) cin >> rC[i][0] >> rC[i][1] >> rC[i][2];
	FOR(i, 0, 3) dp[0][i] = rC[0][i];
	FOR(i, 1, N) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rC[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rC[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rC[i][2];
	}
	cout << *min_element(dp[N-1], dp[N-1] + 3);
}