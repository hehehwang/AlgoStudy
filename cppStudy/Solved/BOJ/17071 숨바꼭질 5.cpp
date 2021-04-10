#include <bits/stdc++.h>
// 17071 숨바꼭질 5
// https://www.acmicpc.net/problem/17071
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using namespace std;

const int LMT = 500'000;
int board[LMT + 2];
int vis[2][LMT + 2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int bro, sis, ans = 0;
    queue<pair<int, int>> Q;
    cin >> sis >> bro;
    Q.push({sis, 0});
    FOR(i, 0, 2) { fill(vis[i], vis[i] + LMT + 2, -1); }
    vis[0][sis] = 0;
    while (!Q.empty()) {
        int v, vt, nvt;
        tie(v, vt) = Q.front();
        nvt = vt + 1;
        Q.pop();
        for (int nv : {2 * v, v + 1, v - 1}) {
            if (nv < 0 || LMT < nv) continue;
            if (vis[nvt % 2][nv] != -1) continue;
            vis[nvt % 2][nv] = nvt;
            Q.push({nv, nvt});
        }
    }
    bool found = false;
    while (bro <= LMT) {
        if (vis[ans % 2][bro] <= ans) {
            found = true;
            break;
        }
        bro += ++ans;
    }
    if (found) cout << ans;
    else
        cout << -1;
}