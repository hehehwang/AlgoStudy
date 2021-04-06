#include <bits/stdc++.h>
using namespace std;
// 17404 RGB거리 2
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
const int mxCost = 1002;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<vector<int>> cost(N, vector<int> (3, 0));
	FOR(i, 0, N) FOR(j, 0, 3) cin >> cost[i][j];
	vector<int> ans(3, 0);
	FOR(k, 0, 3) {
		vector<vector<int>> dp(N, vector<int>(3, mxCost));
		dp[0][k] = cost[0][k];
		FOR(i, 1, N) {
			FOR(j, 0, 3) {
				dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
			}
		}
		ans[k] = min(dp[N - 1][(k + 1) % 3], dp[N - 1][(k + 2) % 3]);
	}
	cout << *min_element(ans.begin(), ans.end());
}