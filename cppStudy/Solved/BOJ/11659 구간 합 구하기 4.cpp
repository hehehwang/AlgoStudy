#include <bits/stdc++.h>
using namespace std;
// 11659 구간 합 구하기 4
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int N, M;
int num[100002];
int dp[100002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	FOR(i, 0, N) cin >> num[i];
	FOR(i, 0, N) dp[i+1] = dp[i] + num[i];
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		cout << (dp[b] - dp[a - 1]) << '\n';
	}
}