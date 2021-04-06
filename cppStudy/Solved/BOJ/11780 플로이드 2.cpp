#include <bits/stdc++.h>
using namespace std;
// 11780 플로이드 2
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int floyd[101][101];
int route[101][101];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	n++;
	FOR(j, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (!floyd[a][b]) floyd[a][b] = c;
		else floyd[a][b] = min(floyd[a][b], c);
		route[a][b] = b;
	}
	FOR(k, 1, n) {
		FOR(i, 1, n) {
			if (i == k) continue;
			FOR(j, 1, n) {
				if (j == k) continue;
				if (i == j) continue;
				int bypass = floyd[i][k] + floyd[k][j];
				if (floyd[i][j] && floyd[i][k] && floyd[k][j]) {
					if (bypass < floyd[i][j]) {
						floyd[i][j] = bypass;
						route[i][j] = route[i][k];
					}
				}
				else if (floyd[i][k] && floyd[k][j]) {
					floyd[i][j] = bypass;
					route[i][j] = route[i][k];
				}
			}
		}
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cout << floyd[i][j] << ' ';
		}
		cout << '\n';
	}
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if (i == j) {
				cout << 0 << '\n';
				continue;
			}
			vector<int> enRoute = { i };
			while (enRoute.back() != j) {
				enRoute.push_back(route[enRoute.back()][j]);
			}
			cout << enRoute.size() << ' ';
			for (auto r : enRoute) cout << r << ' ';
			cout << '\n';
		}
	}
}