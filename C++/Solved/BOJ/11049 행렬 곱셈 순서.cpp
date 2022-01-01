#include <bits/stdc++.h>
// 11049 행렬 곱셈 순서
// https://www.acmicpc.net/problem/11049
#define X first
#define Y second
typedef long long ll;
using namespace std;

int N;
ll dp[502][502];
pair<int, int> arr[502];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        arr[i] = {a, b};
    }
    for (int i = 0; i < N - 1; i++) {
        // ab * bc = abc
        dp[i][i + 1] = arr[i].X * arr[i].Y * arr[i + 1].Y;
    }
    // l: 계산하는 부분의 길이
    for (int l = 1; l < N; l++) {
        // st: 계산하는 부분의 시작지점
        for (int st = 0; st + l < N; st++) {
            int en = st + l;
            // k: 분할 위치
            for (int k = st; k < st + l; k++) {
                ll calc = dp[st][k] + dp[k + 1][en] + arr[st].X * arr[k + 1].X * arr[en].Y;
                dp[st][en] = (dp[st][en]) ? min(dp[st][en], calc) : calc;
            }
        }
    }
    cout << dp[0][N - 1];
}