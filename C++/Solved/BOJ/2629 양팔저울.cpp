#include <bits/stdc++.h>
// 2629 양팔저울
// https://www.acmicpc.net/problem/2629
using namespace std;

vector<vector<bool>> dp(32, vector<bool>(40002));
queue<int> Q[2];
int choo[32], C, W;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> C;
    for (int i = 1; i <= C; i++) cin >> choo[i];
    dp[0][0] = true;
    Q[1].push(0);
    for (int i = 1; i <= C; i++) {
        while (Q[i % 2].size()) {
            int w = Q[i % 2].front();
            Q[i % 2].pop();
            for (int nw : {w, w + choo[i], abs(w - choo[i])}) {
                if (dp[i][nw]) continue;
                dp[i][nw] = true;
                Q[(i + 1) % 2].push(nw);
            }
        }
    }
    cin >> W;
    for (int i = 0; i < W; i++) {
        int w;
        cin >> w;
        cout << (dp[C][w] ? 'Y' : 'N') << ' ';
    }
}