#include <bits/stdc++.h>
// 11657 타임머신 [Bellman-Ford]
// https://www.acmicpc.net/problem/11657
using namespace std;
const int INF = 1e9 + 2;
int N, M, a, b, c, dist[502];
vector<pair<int, int>> adj[6002];
bool minusCycle = false;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    fill(dist, dist + 502, INF);
    dist[1] = 0;
    for (int i = 0; i < N; i++) {
        for (int st = 1; st <= N; st++) {
            for (auto &p : adj[st]) {
                int c, en;
                tie(c, en) = p;
                if (dist[st] == INF || dist[en] <= dist[st] + c) continue;
                if (i == N - 1) minusCycle = true;
                dist[en] = dist[st] + c;
            }
        }
    }
    if (minusCycle)
        cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            cout << ((dist[i] == INF) ? -1 : dist[i]) << '\n';
        }
    }
}