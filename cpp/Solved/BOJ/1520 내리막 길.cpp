#include <bits/stdc++.h>
// 1520 내리막 길
// https://www.acmicpc.net/problem/1520
using namespace std;

priority_queue<tuple<int, int, int>> pQ;
int dp[502][502], arr[502][502], R, C;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) cin >> arr[r][c];
    pQ.push({arr[0][0], 0, 0});
    dp[0][0] = 1;
    while (pQ.size()) {
        int v, r, c;
        tie(v, r, c) = pQ.top();
        pQ.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + "1102"[k] - '0' - 1;
            int nc = c + "0211"[k] - '0' - 1;
            if (nr < 0 || nc < 0 || R <= nr || C <= nc) continue;
            if (arr[r][c] <= arr[nr][nc]) continue;
            if (!dp[nr][nc]) pQ.push({arr[nr][nc], nr, nc});
            dp[nr][nc] += dp[r][c];
        }
    }
    // for (int r = 0; r < R; r++) {
    //     for (int c = 0; c < C; c++) cout << dp[r][c] << ' ';
    //     cout << '\n';
    // }
    cout << dp[R - 1][C - 1];
}