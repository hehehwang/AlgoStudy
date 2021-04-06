#include <bits/stdc++.h>
using namespace std;
// 5014 스타트링크
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define R first
#define C second

int tot, start, dest, up, down;
int build[1000002];
queue<int> Q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tot >> start >> dest >> up >> down;
	int delta[2] = { up, -1 * down };
	Q.push(start);
	build[start] = 1;
	while (!Q.empty() && !build[dest]) {
		int v = Q.front(); Q.pop();
		for (int d : delta) {
			int nv = v + d;
			if (nv <= 0 || tot < nv) continue;
			if (build[nv]) continue;
			build[nv] = build[v] + 1;
			Q.push(nv);
		}
	}
	//FOR(i, 0, tot+1) cout << build[i] << ' ';
	//cout << '\n';
	if (build[dest]) cout << build[dest] - 1;
	else cout << "use the stairs";
}