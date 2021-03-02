#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 12094 2048(Hard) [Pretty but slow]
// TODO: make it faster
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second

int bN;
int board[22][22];
int nowMax;
pair<int, int> rotateCurr(int i, int j, int dir) {
	pair<int, int> curr;
	if (dir == 0)  curr = { i, bN - j - 1 };
	else if (dir == 1) curr = { bN - j - 1, i };
	else if (dir == 2) curr = { i, j };
	else curr = { j, i };
	return curr;
}
void tilt(int dir) {
	FOR(i, 0, bN) {
		queue<int> Q;
		FOR(j, 0, bN) {
			pair<int, int> curr = rotateCurr(i, j, dir);
			if (board[curr.X][curr.Y]) Q.push(board[curr.X][curr.Y]);
			board[curr.X][curr.Y] = 0;
		}
		int j = 0;
		while (!Q.empty()) {
			pair<int, int> cursor = rotateCurr(i, j, dir);
			int v = Q.front(); Q.pop();
			if (!board[cursor.X][cursor.Y]) board[cursor.X][cursor.Y] = v;
			else if (board[cursor.X][cursor.Y] == v) {
				board[cursor.X][cursor.Y] *= 2;
				j++;
			}
			else {
				j++;
				cursor = rotateCurr(i, j, dir);
				board[cursor.X][cursor.Y] = v;
			}
		}
	}
}
void dfs(int depth) {
	if (depth == 10) {
		FOR(i, 0, bN) FOR(j, 0, bN) nowMax = max(board[i][j], nowMax);
		return;
	}
	int boardPrev[22][22] = {};
	FOR(i, 0, bN) FOR(j, 0, bN) boardPrev[i][j] = board[i][j];
	FOR(k, 0, 4) {
		tilt(k);
		// type 1 pruning
		bool isSame = true;
		FOR(i, 0, bN) {
			if (!isSame) break;
			FOR(j, 0, bN) {
				if (boardPrev[i][j] != board[i][j]) {
					isSame = false;
					break;
				}
			}
		}
		if (isSame) {
			FOR(i, 0, bN) FOR(j, 0, bN) board[i][j] = boardPrev[i][j]; // rollback
			continue;
		}
		// type 2 pruning
		int tmpMax = 0;
		FOR(i, 0, bN) FOR(j, 0, bN) tmpMax = max(board[i][j], tmpMax);
		if ((tmpMax << (9 - depth) <= nowMax)) {
			FOR(i, 0, bN) FOR(j, 0, bN) board[i][j] = boardPrev[i][j]; // rollback
			continue;
		}
		dfs(depth + 1);
		FOR(i, 0, bN) FOR(j, 0, bN) board[i][j] = boardPrev[i][j]; // rollback
	}
	return;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> bN;
	FOR(i, 0, bN) FOR(j, 0, bN)	cin >> board[i][j];
	FOR(i, 0, bN) FOR(j, 0, bN) nowMax = max(board[i][j], nowMax);
	dfs(0);
	cout << nowMax;
}