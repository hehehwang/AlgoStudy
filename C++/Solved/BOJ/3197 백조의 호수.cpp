#include <bits/stdc++.h>
// 3197 백조의 호수
// https://www.acmicpc.net/problem/3197
using namespace std;
using PII = pair<int, int>;

int R, C, ans, dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
PII dest;
bool bfs(vector<string> &board, queue<PII> &q, queue<PII> &q_next, vector<vector<bool>> &vis, bool is_swan) {
    while (q.size()) {
        PII cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i], nc = cur.second + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || vis[nr][nc])
                continue;
            if (is_swan && PII({nr, nc}) == dest) {
                return true;
            } else if (board[nr][nc] == '.') {
                q.push({nr, nc});
            } else if (board[nr][nc] == 'X') {
                q_next.push({nr, nc});
            }
            vis[nr][nc] = true;
        }
    }
    return false;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    vector<string> board(R);
    queue<PII> water, swan, water_next, swan_next;
    vector<vector<bool>> swan_vis(R, vector<bool>(C, false)), water_vis(R, vector<bool>(C, false));
    for (int i = 0; i < R; i++)
        cin >> board[i];

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 'L') {
                if (swan_next.empty()) {
                    swan_vis[r][c] = true;
                    swan_next.push({r, c});
                } else {
                    dest = {r, c};
                }
                board[r][c] = '.';
            }
            if (board[r][c] != 'X') {
                water_next.push({r, c});
                water_vis[r][c] = true;
            }
        }
    }
    while (++ans) {
        while (swan_next.size()) {
            swan.push(swan_next.front());
            swan_next.pop();
        }
        while (water_next.size()) {
            board[water_next.front().first][water_next.front().second] = '.';
            water.push(water_next.front());
            water_next.pop();
        }
        if (bfs(board, swan, swan_next, swan_vis, true)) {
            cout << ans - 1;
            return 0;
        }
        bfs(board, water, water_next, water_vis, false);
    }
}