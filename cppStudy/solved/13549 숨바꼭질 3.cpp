#include <bits/stdc++.h>
using namespace std;
// 13549 숨바꼭질 3
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define R first
#define C second
constexpr int LMT = 100001;

int board[LMT+2];
int s, b;
queue<int> Q;
void teleport(int num) {
	int tmp = num;
	if (!tmp) return;
	while (tmp < LMT && !board[b]) {
		if (!board[tmp]) {
			board[tmp] = board[num];
			Q.push(tmp);
			if (tmp == b) return;
		}
		tmp <<= 1;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> b;
	board[s] = 1;
	Q.push(s);
	teleport(s);
	while (!board[b]) {
		int v = Q.front(); Q.pop();
		vector<int> nvLst = { v + 1, v - 1 };
		for (int nv : nvLst) {
			if (nv < 0 || LMT <= nv) continue;
			if (board[nv]) continue;
			board[nv] = board[v] + 1;
			Q.push(nv);
			teleport(nv);
		}
	}
	cout << board[b]-1;
}