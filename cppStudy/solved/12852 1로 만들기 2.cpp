#include <bits/stdc++.h>
using namespace std;
// 12852 1로 만들기 2
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int N;
int dp[1000003];
vector<int> route = { 0 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[1000002] = 1000000;
	FOR(i, 1, N + 1) {
		int v1 = i - 1, v2 = 1000002, v3 = 1000002;
		if (!(i % 2)) v2 = i / 2;
		if (!(i % 3)) v3 = i / 3;
		pair<int, int> p1 = { dp[v1], v1 }, p2 = { dp[v2], v2 }, p3 = { dp[v3], v3 };
		pair<int, int> r = min({ p1, p2, p3 });
		dp[i] = r.first + 1;
		route.push_back(r.second);
	}
	cout << dp[N] - 1 << '\n';
	int dest = N;
	while (dest != 1) {
		cout << dest << ' ';
		dest = route[dest];
	}
	cout << 1;