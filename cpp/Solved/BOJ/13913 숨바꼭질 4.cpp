#include <bits/stdc++.h>
using namespace std;
// 13913 숨바꼭질 4
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int LMT = 100001;

int board[LMT + 2];
int prep[LMT + 2];
int s, b;
queue<int> Q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> b;
	board[s] = 1;
	prep[s] = s;
	Q.push(s);
	while (!board[b]) {
		int v = Q.front(); Q.pop();
		vector<int> nvLst = { v + 1, v - 1, 2 * v };
		for (int nv : nvLst) {
			if (nv < 0 || LMT <= nv) continue;
			if (board[nv]) continue;
			board[nv] = board[v] + 1;
			prep[nv] = v;
			Q.push(nv);
		}
	}
	cout << board[b]-1 << '\n';
	deque<int> prepositions;
	prepositions.push_front(b);
	while (prepositions.front() != s) {
		prepositions.push_front(prep[prepositions.front()]);
	}
	for (auto p : prepositions) cout << p << ' ';
}