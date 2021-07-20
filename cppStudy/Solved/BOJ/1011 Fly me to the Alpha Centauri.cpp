#include <bits/stdc++.h>
// Fly me to the Alpha Centauri
// https://www.acmicpc.net/problem/1011
using namespace std;
typedef long long ll;

// 다음 공간이동으로 이동할 수 있는 최대 거리의 역
// https://oeis.org/A033638
ll solve(ll k) {
    return floor(2 * sqrt(k) - 1e-9);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    ll a, b;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> a >> b;
        ll dist = b - a;
        cout << solve(dist) << '\n';
    }
}