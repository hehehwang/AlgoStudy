#include <bits/stdc++.h>
using namespace std;
// 1799 비숍 [Naive2]
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using PII = pair<int, int>;

bool D[20];
int ans;
int board[12][12];
int N;
vector<PII> space[20];
void b(int idx, int cnt) {
	if (idx == 2*N) {
		ans = max(ans, cnt);
		return;
	}
	for (auto v : space[idx]) {
		int r, c;
		tie(r, c) = v;
		if (D[r + c]) continue;
		D[r + c] = true;
		b(idx + 1, cnt + 1);
		D[r + c] = false;
	}
	b(idx + 1, cnt);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	FOR(i, 0, N) FOR(j, 0, N) {
		int d;
		cin >> d;
		if (d) space[N+i-j-1].push_back({ i, j });
	}
	b(0, 0);
	cout << ans;
}