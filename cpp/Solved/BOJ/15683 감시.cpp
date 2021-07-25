#include <bits/stdc++.h>
using namespace std;
// 15683 감시
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int row, col;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };
int office[22][22], officeCpy[22][22];
vector < pair<int, int>> cctvCoord;
int cctvN;

bool oob(int r, int c) { return r < 0 || row <= r || c < 0 || col <= c; }

void upd(int r, int c, int dir) {
	dir %= 4;
	if (oob(r, c) || officeCpy[r][c] == 6) return;
	if (!officeCpy[r][c]) officeCpy[r][c] = 7;
	upd(r + dr[dir], c + dc[dir], dir);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> row >> col;
	FOR(i, 0, row) {
		FOR(j, 0, col) {
			cin >> office[i][j];
			if (office[i][j] != 6 && office[i][j]) {
				cctvCoord.push_back({ i, j });
				cctvN++;
			}
		}
	}
	int bs = 65;
	FOR(combi, 0, 1 << (2 * cctvN)) {
		FOR(i, 0, row) {
			FOR(j, 0, col)	officeCpy[i][j] = office[i][j];
		}
		int brute = combi;
		FOR(cctvIdx, 0, cctvN) {
			int dir = brute % 4;
			brute /= 4;

			int cr = cctvCoord[cctvIdx].first;
			int cc = cctvCoord[cctvIdx].second;
			if (officeCpy[cr][cc] == 1) 
				upd(cr, cc, dir);
			else if (officeCpy[cr][cc] == 2) {
				upd(cr, cc, dir);
				upd(cr, cc, dir + 2);
			}
			else if (officeCpy[cr][cc] == 3) {
				upd(cr, cc, dir);
				upd(cr, cc, dir + 1);
			}
			else if (officeCpy[cr][cc] == 4) {
				upd(cr, cc, dir);
				upd(cr, cc, dir + 1);
				upd(cr, cc, dir + 2);
			}
			else {
				upd(cr, cc, dir);
				upd(cr, cc, dir + 1);
				upd(cr, cc, dir + 2);
				upd(cr, cc, dir + 3);
			}
		}

		int b = 0;
		FOR(i, 0, row) {
			FOR(j, 0, col) {
				// cout << officeCpy[i][j] << ' ' ;
				if (!officeCpy[i][j]) b++;
			}
			// cout << '\n';
		}
		// cout << '\n';
		bs = min(bs, b);
	}
	cout << bs;
}