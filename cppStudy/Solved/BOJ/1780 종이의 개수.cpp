#include <bits/stdc++.h>
using namespace std;
// 1780 종이의 개수
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int LMT = 2187;

int bN;
int board[LMT + 2][LMT + 2];
int ans[3];
void f(int r1, int r2, int c1, int c2) {
    int v = board[r1][c1];
    bool u = true;
    FOR(i, r1, r2) {
        if (!u) break;
        FOR(j, c1, c2) {
            if (!u) break;
            if (board[i][j] != v) u = false;
        }
    }
    if (u) ans[v + 1]++;
    else {
        int rot = r1 + (r2 - r1) / 3;
        int cot = c1 + (c2 - c1) / 3;
        int rtt = r1 + (r2 - r1) * 2 / 3;
        int ctt = c1 + (c2 - c1) * 2 / 3;
        f(r1, rot, c1, cot);
        f(rot, rtt, c1, cot);
        f(rtt, r2, c1, cot);
        f(r1, rot, cot, ctt);
        f(rot, rtt, cot, ctt);
        f(rtt, r2, cot, ctt);
        f(r1, rot, ctt, c2);
        f(rot, rtt, ctt, c2);
        f(rtt, r2, ctt, c2);
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> bN;
    FOR(i, 0, bN) FOR(j, 0, bN) cin >> board[i][j];
    f(0, bN, 0, bN);
    for (auto a : ans) cout << a << '\n';
}