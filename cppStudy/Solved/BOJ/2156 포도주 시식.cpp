#include <bits/stdc++.h>
using namespace std;
// 2156 포도주 시식
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int dp[10002][2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int mV = 0;
    if (N == 1) {
        cin >> mV;
        cout << mV; 
        return 0;
    }
    cin >> dp[0][0] >> dp[1][0];
    dp[1][1] = dp[0][0] + dp[1][0];
    mV = max({ dp[0][0], dp[0][1], dp[1][1] });
    FOR(i, 2, N) {
        int wine;
        cin >> wine;
        if (i == 2) dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + wine;
        else dp[i][0] = max({ dp[i - 3][0], dp[i - 3][1], dp[i - 2][0], dp[i - 2][1] }) + wine;
        dp[i][1] = dp[i - 1][0] + wine;
        mV = max({ mV, dp[i][0], dp[i][1] });
    }
    cout << mV;
}