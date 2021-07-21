#include <bits/stdc++.h>
// 13305 주유소
// https://www.acmicpc.net/problem/13305
using namespace std;
typedef long long ll;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll minPrice, t, ans = 0;
    vector<ll> dists(N), prices(N);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> t;
        dists.push_back(t);
    }
    cin >> minPrice;
    for (int i = 0; i < N - 1; i++) {
        cin >> t;
        prices.push_back(t);
    }
    for (int i = 0; i < N - 1; i++) {
        ans += dists[i] * minPrice;
        minPrice = min(minPrice, prices[i]);
    }
    cout << ans;
}