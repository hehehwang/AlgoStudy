#include <bits/stdc++.h>
using namespace std;
// 2493 탑
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int N;
int twrNo;
stack <pair<int, int>> twr;
stack <pair<int, int>> stk;
int res[500002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	twr.push({ 100000001, 0 });
	FOR(i, 1, N + 1) {
		int v;
		cin >> v;
		twr.push({ v, i });
	}

	while (1) {
		stk.push(twr.top()); twr.pop();
		if (twr.empty()) break;
		while (!stk.empty()) {
			if (stk.top().first <= twr.top().first) {
				res[stk.top().second] = twr.top().second;
				stk.pop();
			}
			else {
				stk.push(twr.top()); twr.pop();
			}
		}
	}
	FOR(i, 1, N + 1) cout << res[i] << ' ';
}