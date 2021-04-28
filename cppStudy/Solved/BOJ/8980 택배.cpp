#include <bits/stdc++.h>
// 8980 택배
// https://www.acmicpc.net/problem/8980
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using namespace std;

int N, C, M, ans;
int truck[2002];
vector<tuple<int, int, int>> orders;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C >> M;
    int f, t, b;
    FOR(i, 0, M) {
        cin >> f >> t >> b;
        orders.push_back({t, f, b});
    }
    sort(orders.begin(), orders.end());
    for (auto v : orders) {
        tie(t, f, b) = v;
        bool loadable = true;
        FOR(i, f, t) {
            if (C == truck[i]) {
                loadable = false;
                break;
            }
            if (C - truck[i] < b) b = C - truck[i];
        }
        if (loadable) {
            ans += b;
            FOR(i, f, t)
            truck[i] += b;
        }
    }
    cout << ans;
}