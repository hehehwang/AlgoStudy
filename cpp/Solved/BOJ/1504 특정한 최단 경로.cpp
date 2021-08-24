#include <bits/stdc++.h>
// 1504 특정한 최단 경로
// https://www.acmicpc.net/problem/1504
using namespace std;
typedef pair<int, int> PII;
const int INF = 1e9 + 2;

int N, E, a, b, c, V1, V2, dist[3][802];
vector<PII> adj[802];
void dijk(int s, int* d) {
    priority_queue<PII, vector<PII>, greater<>> pQ;
    pQ.push({0, s});
    d[s] = 0;
    while (pQ.size()) {
        int c, v;
        tie(c, v) = pQ.top();
        pQ.pop();
        if (d[v] != c) continue;
        for (PII p : adj[v]) {
            int nc, nv;
            tie(nc, nv) = p;
            nc += c;
            if (d[nv] <= nc) continue;
            d[nv] = nc;
            pQ.push({nc, nv});
        }
    }
}
// ans1: 1 -> V1 -> V2 -> N
// ans2: 1 -> V2 -> V1 -> N
// dijk from 1, V1, V2
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> V1 >> V2;

    for (int i = 0; i < 3; i++)
        fill(dist[i], dist[i] + 802, INF);
    dijk(1, dist[0]);
    dijk(V1, dist[1]);
    dijk(V2, dist[2]);

    long long ans1 = 0, ans2 = 0;
    if ((dist[0][V1] != INF) && (dist[1][V2] != INF) && (dist[2][N] != INF))
        ans1 = dist[0][V1] + dist[1][V2] + dist[2][N];
    if ((dist[0][V2] != INF) && (dist[2][V1] != INF) && (dist[1][N] != INF))
        ans2 = dist[0][V2] + dist[2][V1] + dist[1][N];

    if (ans1 && ans2) cout << min(ans1, ans2);
    else if (ans1)
        cout << ans1;
    else if (ans2)
        cout << ans2;
    else
        cout << -1;
}
