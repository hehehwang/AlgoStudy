#include <bits/stdc++.h>
using namespace std;
// 10942 팰린드롬?
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int dp[2002][2002]; // 0: not calculated, 1: not pel, 2: is pel
int arr[2002];
int isPel(int a, int b) {
	if (dp[a][b]) return dp[a][b];
	if ((b == a + 1 || isPel(a + 1, b - 1) == 2) && arr[a] == arr[b]) dp[a][b] = 2;
	else dp[a][b] = 1;
	return dp[a][b];
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N;
	FOR(i, 1, N+1) {
		cin >> arr[i];
		dp[i][i] = 2;
	}
	cin >> M;
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		if (isPel(a, b) == 1) cout << 0 << '\n';
		else cout << 1 << '\n';
	}
}