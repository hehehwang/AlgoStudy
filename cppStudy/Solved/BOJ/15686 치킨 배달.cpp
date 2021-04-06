#include <bits/stdc++.h>
using namespace std;
// 15686 치킨 배달
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second

vector<int> combi;
vector<pair<int, int>> house, chicken;
int cN, M, ht, ct;
int city[52][52];

int cD(pair<int, int> x, pair<int, int> y) { // chicken distance
	return abs(x.X - y.X) + abs(x.Y - y.Y);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> cN >> M;
	FOR(i, 0, cN) {
		FOR(j, 0, cN) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				house.push_back({ i, j });
				ht++;
			}
			else if (city[i][j] == 2) {
				chicken.push_back({ i, j });
				ct++;
			}
		}
	}
	int minCcd = 9999;
	FOR(i, 0, ct) {
		if (i < M) combi.push_back(1);
		else combi.push_back(0);
		// cout << combi[i] << ' ';
	}
	// cout << '\n';
	sort(combi.begin(), combi.end());
	do {
		int ccd = 0; // city chicken distance
		FOR(h, 0, ht) {
			int cdh = 101;
			FOR(c, 0, ct) {
				if (!combi[c]) continue;
				cdh = min(cdh, cD(chicken[c], house[h]));
			}
			ccd += cdh;
		}
		minCcd = min(minCcd, ccd);
	} while (next_permutation(combi.begin(), combi.end()));
	cout << minCcd;
}