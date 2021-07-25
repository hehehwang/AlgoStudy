#include <bits/stdc++.h>
using namespace std;
// 1958 LCS 3
#define FOR(i, n, m) for(int i=(n); i<m; i++)
#define FORR(i, n, m) for(int i=(n); i>m; i--)

int dp[102][102][102];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int s1l = s1.length(), s2l = s2.length(), s3l = s3.length();
	int ans = 0;

	FOR(i, 0, s1l) {
		FOR(j, 0, s2l) {
			FOR(k, 0, s3l) {
				if (s1[i] == s2[j] && s2[j] == s3[k]) {
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				}
				else dp[i + 1][j + 1][k + 1] = max({ dp[i + 1][j + 1][k], dp[i + 1][j][k + 1], dp[i][j + 1][k + 1] });
			}
		}
	}
	cout << dp[s1l][s2l][s3l];
}