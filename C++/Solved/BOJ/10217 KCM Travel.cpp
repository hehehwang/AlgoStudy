#include <bits/stdc++.h>
// 10217 KCM Travel
// https://www.acmicpc.net/problem/10217
using namespace std;
typedef tuple<int, int, int> TI3;  // distance, cost, node
const int INF = 1e9 + 2;

int dist[102][10002];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;
    while (testCase--) {
        int N, M, K, a, b, c, d, v;
        vector<TI3> adj[102];
        for (int i = 0; i < 102; i++) fill(dist[i], dist[i] + 10002, INF);
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            cin >> a >> b >> c >> d;
            adj[a].push_back({d, c, b});
        }
        priority_queue<TI3, vector<TI3>, greater<>> pQ;
        dist[1][0] = 0;
        pQ.push({0, 0, 1});
        while (pQ.size()) {
            tie(d, c, v) = pQ.top();
            pQ.pop();
            if (dist[v][c] != d) continue;
            for (auto &p : adj[v]) {
                int nd, nc, nv;
                tie(nd, nc, nv) = p;
                nc += c;
                nd += d;
                if (M < nc) continue;
                if (dist[nv][nc] <= nd) continue;
                dist[nv][nc] = nd;
                pQ.push({nd, nc, nv});
            }
        }

        int ans = INF;
        for (int i = 0; i <= M; i++)
            ans = min(ans, dist[N][i]);

        if (ans == INF) cout << "Poor KCM" << '\n';
        else
            cout << ans << '\n';
    }
}