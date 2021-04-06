#include <bits/stdc++.h>
using namespace std;
// 11559 Puyo Puyo
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int row = 12;
constexpr int col = 6;

int board[row][col];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1,  -1, 0, 0 };
void puyoG() {
    FOR(coli, 0, col) {
        int tmp[row] = {};
        int cnt = row - 1;
        for (int i = row - 1; 0 <= i; i--) {
            if (i == -1) break;
            if (!board[i][coli]) continue;
            tmp[cnt] = board[i][coli];
            cnt--;
        }
        FOR(i, 0, row) board[i][coli] = tmp[i];
    }
}
bool puyoPop() {
    bool poped = false;
    int vis[row][col] = {};
    queue<pair<int, int>> Q;
    FOR(i, 0, row) FOR(j, 0, col) {
        if (vis[i][j]) continue;
        if (!board[i][j]) continue;
        int currPuyo = board[i][j];
        vector<pair<int, int>> tonariPuyo = {};
        vis[i][j] = 1;
        Q.push({ i, j });
        tonariPuyo.push_back({ i, j });
        while (!Q.empty()) {
            auto v = Q.front(); Q.pop();
            int vr = v.first, vc = v.second;
            FOR(k, 0, 4) {
                int nr = vr + dr[k], nc = vc + dc[k];
                if (nr < 0 || nc < 0 || row <= nr || col <= nc) continue;
                if (vis[nr][nc]) continue;
                if (board[nr][nc] != currPuyo) continue;
                vis[nr][nc] = 1;
                Q.push({ nr, nc });
                tonariPuyo.push_back({ nr, nc });
            }
        }
        if (4 <= tonariPuyo.size()) {
            for (auto p : tonariPuyo) board[p.first][p.second] = 0;
            poped = true;
            Q = {};
        }
    }
    return poped;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string puyoLst = "RGBPY";
    FOR(ri, 0, row) FOR(ci, 0, col) {
        char c;
        cin >> c;
        if (c == '.') continue;
        FOR(k, 0, 5) {
            if (c == puyoLst[k]) {
                board[ri][ci] = k + 1;
                break;
            }
        }
    }
    int ans = 0;
    while (puyoPop()) {
        ans++;
        puyoG();
        //FOR(ri, 0, row) {
        //    FOR(ci, 0, col) {
        //        cout << board[ri][ci] << ' ';
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
    }
    cout << ans;
}