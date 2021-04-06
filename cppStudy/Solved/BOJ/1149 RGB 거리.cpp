#include <bits/stdc++.h>
using namespace std;
// 1149 RGB거리
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

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
		FOR(k, 0, 3) dp[i][k] = min(dp[i - 1][(k + 1) % 3], dp[i - 1][(k + 2) % 3]) + rC[i][k];
	}
	cout << *min_element(dp[N - 1], dp[N - 1] + 3);
}