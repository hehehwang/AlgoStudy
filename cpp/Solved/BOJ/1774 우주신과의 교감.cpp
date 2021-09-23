#include <bits/stdc++.h>
// 1774 우주신과의 교감
// https://www.acmicpc.net/problem/1774
using namespace std;
using PII = pair<int, int>;

int N, M, grp[1002];
PII gods[1002];
vector<tuple<double, int, int>> edges;
int find(int v) {
    if (grp[v] == v) return v;
    return grp[v] = find(grp[v]);
}
void unite(int a, int b) {
    if (b < a) swap(a, b);
    grp[find(b)] = find(a);
}
double dist(PII a, PII b) {
    auto [ax, ay] = a;
    auto [bx, by] = b;
    return sqrt(1ll * (ax - bx) * (ax - bx) + 1ll * (ay - by) * (ay - by));
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);

    cin >> N >> M;
    int a, b;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b;
        gods[i] = {a, b};
    }
    for (int i = 1; i <= N; i++) grp[i] = i;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        unite(a, b);
    }
    edges.reserve((N * (N - 1)) / 2);
    for (int st = 1; st < N; st++)
        for (int en = st + 1; en <= N; en++)
            edges.push_back({dist(gods[st], gods[en]), st, en});
    sort(edges.begin(), edges.end());

    double ans = 0;
    int cnt = 0;
    for (auto e : edges) {
        auto [c, st, en] = e;
        if (find(st) == find(en)) continue;
        ans += c;
        unite(st, en);
        if (++cnt == N - M - 1) break;
    }
    cout << ans;
}