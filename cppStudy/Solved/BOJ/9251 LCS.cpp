#include <bits/stdc++.h>
using namespace std;
// 9251 LCS
#define FOR(i, n, m) for(int i=(n); i<m; i++)
#define FORR(i, n, m) for(int i=(n); i>m; i--)

int dp[1002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int s1l = s1.length(), s2l = s2.length();
	for (char vc : s1) {
		FORR(i, s2l-1, -1) {
			if (s2[i] == vc) {
				if (i) dp[i] = *max_element(dp, dp + i) + 1;
				else dp[i] = 1;
			}
		}
	}
	cout << *max_element(dp, dp + s2l);
}