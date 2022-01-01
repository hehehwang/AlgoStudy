#include <bits/stdc++.h>
using namespace std;
// 9252 LCS 2
#define FOR(i, n, m) for(int i=(n); i<m; i++)
#define FORR(i, n, m) for(int i=(n); i>m; i--)

int dp[1002][1002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	int s1l = s1.length(), s2l = s2.length();
	int ans = 0;
	
	FOR(i, 0, s1l) {
		FOR(j, 0, s2l) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	cout << dp[s1l][s2l] << '\n';
	
	int i = s1l, j = s2l;
	vector<char> ansS;
	while (i * j) {
		if (s1[i-1] == s2[j-1]) {
			ansS.push_back(s1[i - 1]);
			i--; j--;
		}
		else if (dp[i][j-1] < dp[i-1][j]) i--;
		else j--;
	}
	for (auto it = ansS.rbegin(); it != ansS.rend(); it++) {
		cout << *it;
	}
}