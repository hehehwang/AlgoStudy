#include <bits/stdc++.h>
using namespace std;
// 11726 2xn 타일링
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int n;
const int MOD = 10007;
int dp[1002] = { 1, 2, };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	FOR(i, 2, n) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	cout << dp[n - 1];
}