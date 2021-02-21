#include <bits/stdc++.h>
using namespace std;
// 7579 앱
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define FORR(i, n, m) for(int i=(n); (m)<i; i--)
using PII = pair<int, int>;

int dp[10002];
PII arr[102];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, costT = 0;
	cin >> N >> M;
	FOR(i, 0, N) cin >> arr[i].first;
	FOR(i, 0, N) {
		cin >> arr[i].second;
		costT += arr[i].second;
	}
	FOR(i, 0, N) {
		int cost, memory;
		tie(memory, cost) = arr[i];
		FORR(j, costT, cost-1) {
			dp[j] = max(dp[j], dp[j-cost] + memory);
		}
	}
	FOR(i, 0, 10001) if (M <= dp[i]) {
		cout << i;
		break;
	}
}