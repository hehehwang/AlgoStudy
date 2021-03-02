#include <bits/stdc++.h>
using namespace std;
// 12094 2048(Hard)
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define FORR(i, n, m) for(int i=(n); (m)<i; i--)
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
    queue<int> Q;
    if (dir == 0) {
        FOR(j, 0, bN) {
            FOR(i, 0, bN) {
                if (board[i][j]) {
                    Q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = 0;
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                if (!board[idx][j]) board[idx][j] = v;
                else if (board[idx][j] == v) {
                    board[idx][j] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[idx][j] = v;
                }
            }
        }
    }
    else if (dir == 1) {
        FOR(j, 0, bN) {
            FORR(i, bN - 1, -1) {
                if (board[i][j]) {
                    Q.push(board[i][j]); board[i][j] = 0;
                }
            }
            int idx = bN - 1;
            while (!Q.empty())
            {
                int v = Q.front();
                Q.pop();
                if (!board[idx][j]) board[idx][j] = v;
                else if (board[idx][j] == v) {
                    board[idx][j] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[idx][j] = v;
                }
            }
        }
    }
    else if (dir == 2) {
        FOR(i, 0, bN) {
            FOR(j, 0, bN) {
                if (board[i][j]) {
                    Q.push(board[i][j]); board[i][j] = 0;
                }
            }
            int idx = 0;
            while (!Q.empty()) {
                int v = Q.front(); Q.pop();
                if (!board[i][idx]) board[i][idx] = v;
                else if (board[i][idx] == v) {
                    board[i][idx] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[i][idx] = v;
                }
            }
        }
    }
    else if (dir == 3) {
        FOR(i, 0, bN) {
            FORR(j, bN - 1, -1) {
                if (board[i][j]) {
                    Q.push(board[i][j]);
                    board[i][j] = 0;
                }
            }
            int idx = bN - 1;
            while (!Q.empty())
            {
                int v = Q.front();
                Q.pop();
                if (!board[i][idx]) board[i][idx] = v;
                else if (board[i][idx] == v) {
                    board[i][idx] *= 2;
                    idx--;
                }
                else if (board[i][idx]) {
                    idx--;
                    board[i][idx] = v;
                }
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
        // type 1 pruning: direction not effective
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
        // type 2 pruning: max estimation
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
    FOR(i, 0, bN) FOR(j, 0, bN) cin >> board[i][j];
    FOR(i, 0, bN) FOR(j, 0, bN) nowMax = max(board[i][j], nowMax);
    dfs(0);
    cout << nowMax;
}