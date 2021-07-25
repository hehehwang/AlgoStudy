#include <bits/stdc++.h>
// 14727 퍼즐 자르기
// https://www.acmicpc.net/problem/14727
using namespace std;
const int mxN = 1'000'002;

int N, rect[mxN], R[mxN], L[mxN];
long long ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> rect[i];
    rect[N + 1] = 0;

    stack<pair<int, int>> stk;
    for (int i = 0; i <= N + 1; i++) {
        while (stk.size()) {
            if (stk.top().second <= rect[i]) break;
            R[stk.top().first] = i;
            stk.pop();
        }
        stk.push({i, rect[i]});
    }
    stk = {};
    for (int i = N + 1; - 1 < i; i--) {
        while (stk.size()) {
            if (stk.top().second <= rect[i]) break;
            L[stk.top().first] = i;
            stk.pop();
        }
        stk.push({i, rect[i]});
    }
    for (int i = 1; i <= N; i++)
        ans = max(ans, 1ll * rect[i] * (R[i] - L[i] - 1));
    cout << ans;
}