#include <bits/stdc++.h>
using namespace std;
// 11404 플로이드
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int floyd[101][101];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	FOR(j, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (!floyd[a][b]) floyd[a][b] = c;
		else floyd[a][b] = min(floyd[a][b], c);
	}
	FOR(k, 0, n) {
		FOR(i, 0, n) {
			if (i == k) continue;
			FOR(j, 0, n) {
				if (j == k) continue;
				if (i == j) continue;
				int bypass = floyd[i][k] + floyd[k][j];
				if (floyd[i][j] && floyd[i][k] && floyd[k][j]) floyd[i][j] = min(floyd[i][j], bypass);
				else if (floyd[i][k] && floyd[k][j]) floyd[i][j] = bypass;
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cout << floyd[i][j] << ' ';
		}
		cout << '\n';
	}
}