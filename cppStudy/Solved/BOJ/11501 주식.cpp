#include <bits/stdc++.h>
// 11501 주식
// https://www.acmicpc.net/problem/11501
using namespace std;

int stock[1'000'002];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc, days;
    cin >> tc;
    for (int t = 0; t < tc; t++) {
        long long ans = 0;
        int mx = 0;
        cin >> days;
        for (int d = 0; d < days; d++) cin >> stock[d];
        for (int d = days; 0 < d; d--) {
            mx = max(mx, stock[d - 1]);
            ans += max(mx - stock[d - 1], 0);
        }
        cout << ans << '\n';
    }
}