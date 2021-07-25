#include <bits/stdc++.h>
using namespace std;
// 1799 비숍
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using PII = pair<int, int>;

bool D[2][20];
int ans[2];
int board[12][12];
int N;
vector<PII> space[2][20];
void b(int idx, int cnt, int color) {
	if (idx == 2*N) {
		ans[color] = max(ans[color], cnt);
		return;
	}
	for (auto v : space[color][idx]) {
		int r, c;
		tie(r, c) = v;
		if (D[color][r + c]) continue;
		D[color][r + c] = true;
		b(idx + 1, cnt + 1, color);
		D[color][r + c] = false;
	}
	b(idx + 1, cnt, color);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	FOR(i, 0, N) FOR(j, 0, N) {
		int d;
		cin >> d;
		if (d) {
			if ((i+j)%2) space[0][N + i - j - 1].push_back({ i, j });
			else space[1][N + i - j - 1].push_back({ i, j });
		}
	}
	b(0, 0, 0);
	b(0, 0, 1);
	cout << ans[0] + ans[1];
}