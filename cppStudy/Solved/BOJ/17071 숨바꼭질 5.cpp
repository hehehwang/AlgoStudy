#include <bits/stdc++.h>
// 17071 숨바꼭질 5
// https://www.acmicpc.net/problem/17071
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using namespace std;

// const int LMT = 500'001;
const int LMT = 101;
int board[LMT + 2];
int vis[2][LMT + 2];
int bro, sis;
int ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    FOR(i, 0, 2)
    fill(vis[i], vis[i] + LMT + 2, -1);
    cin >> sis >> bro;
    queue<pair<int, int>> Q;
    Q.push({sis, 0});
    while (!Q.empty()) {
        int v, vt;
        tie(v, vt) = Q.front();
        Q.pop();
        for (int nv : {v + 1, v - 1, 2 * v}) {
            if (nv < 0 || LMT <= nv)
                continue;
            if (vis[(vt + 1) % 2][nv] != -1)
                continue;
            vis[(vt + 1) % 2][nv] = vt + 1;
            Q.push({nv, vt + 1});
        }
    }
    while (bro+ans<=LMT){
        if (vis[ans % 2][bro + ans] < ans) break;
        bro += ++ans;
    }
    cout << ans;
}