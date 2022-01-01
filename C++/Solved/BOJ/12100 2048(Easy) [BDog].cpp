#include <bits/stdc++.h>
using namespace std;
// 12100 2048 (Easy)(BDog)
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int bN;
int board[22][22];
int boardOrig[22][22];

void rotate() {
	int tmp[22][22];
	FOR(i, 0, bN) FOR(j, 0, bN) tmp[i][j] = board[i][j];
	FOR(i, 0, bN) FOR(j, 0, bN) board[i][j] = tmp[bN - j - 1][i];
}

void tilt(int dir) {
	FOR(i, 0, dir) rotate();
	FOR(ln, 0, bN) {
		int tmp[22] = {};
		int idx = 0;
		FOR(i, 0, bN) {
			if (!board[ln][i]) continue;
			if (!tmp[idx]) tmp[idx] = board[ln][i];
			else if (tmp[idx] == board[ln][i]) {
				tmp[idx] *= 2;
				idx++;
			}
			else {
				idx++;
				tmp[idx] = board[ln][i];
			}
		}
		FOR(i, 0, bN) board[ln][i] = tmp[i];
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> bN;
	FOR(i, 0, bN) FOR(j, 0, bN)	cin >> boardOrig[i][j];
	int mV = 0;
	FOR(combi, 0, 1 << 10) {
		int brute = combi;
		FOR(i, 0, bN) FOR(j, 0, bN)	board[i][j] = boardOrig[i][j];
		FOR(i, 0, 5) {
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		int V = 0;
		FOR(i, 0, bN) FOR(j, 0, bN)	V = max(board[i][j], V);
		mV = max(mV, V);
	}
	cout << mV;
}