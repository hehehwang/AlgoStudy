#include <bits/stdc++.h>
// 2293 동전 1
// https://www.acmicpc.net/problem/2293
using namespace std;

int N, K, dp[2][10002], arr[102];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr, arr + N + 1);
    for (int k = 0; k <= K; k++)
        dp[1][k] = !(k % arr[1]);
    for (int i = 2; i <= N; i++) {
        for (int k = 0; k <= K; k++) {
            int r = dp[(i - 1) % 2][k], ktmp = k;
            while (arr[i] <= ktmp) {
                ktmp -= arr[i];
                r += dp[(i - 1) % 2][ktmp];
            }
            dp[i % 2][k] = r;
        }
    }
    cout << dp[N % 2][K];
}