#include <bits/stdc++.h>
// 1654 랜선 자르기
// https://www.acmicpc.net/problem/1654
using namespace std;
typedef long long ll;

ll arr[10002], mx;
int N, K;
int cables(ll l) {
    int cnt = 0;
    for (int i = 0; i < K; i++) cnt += arr[i] / l;
    return cnt;
}
int bs(ll s, ll e) {
    if (e == s + 1) return s;
    ll m = (s + e) / 2;
    if (cables(m) < N) return bs(s, m);
    return bs(m, e);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    cout << bs(1, mx + 1);
}