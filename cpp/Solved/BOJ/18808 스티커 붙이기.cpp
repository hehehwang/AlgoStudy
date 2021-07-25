#include <bits/stdc++.h>
using namespace std;
// 18808 스티커 붙이기
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int nbRow, nbCol, stkN;
int nb[42][42];
int stk[12][12];
int stkR, stkC;

bool match(int nbR, int nbC) {
	FOR(i, 0, stkR) {
		FOR(j, 0, stkC) {
			if (stk[i][j]) 
				if (nb[nbR + i][nbC + j]) return false;
		}
	}
	return true;
}

void fill(int nbR, int nbC) {
	FOR(i, 0, stkR) {
		FOR(j, 0, stkC) {
			if (stk[i][j]) nb[nbR + i][nbC + j] = 1;
		}
	}
}

void rotate() {
	int tmp[12][12];
	FOR(i, 0, stkR) {
		FOR(j, 0, stkC) {
			tmp[i][j] = stk[i][j];
		}
	}
	FOR(i, 0, stkC) {
		FOR(j, 0, stkR) {
			stk[i][j] = tmp[stkR - j - 1][i];
		}
	}
	swap(stkR, stkC);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> nbRow >> nbCol >> stkN;
	FOR(stkNo, 0, stkN) {
		cin >> stkR >> stkC;
		FOR(r, 0, stkR) {
			FOR(c, 0, stkC) {
				cin >> stk[r][c];
			}
		}
		bool matched = false;
		FOR(angleNo, 0, 4) {
			if (matched) break;
			FOR(nbr, 0, nbRow - stkR + 1) {
				if (matched) break;
				FOR(nbc, 0, nbCol - stkC + 1){
					if (matched) break;
					if (match(nbr, nbc)) {
						fill(nbr, nbc);
						matched = true;
					}
				}
			}
			rotate();
		}
	}
	int total = 0;
	FOR(i, 0, nbRow){
		FOR(j, 0, nbCol) {
			total += nb[i][j];
			// cout << nb[i][j] << ' ';
		}
		// cout << '\n';
	}
	cout << total;
}