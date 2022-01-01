#include <bits/stdc++.h>
// 9370 미확인 도착지
// https://www.acmicpc.net/problem/9370
using namespace std;
typedef pair<int, int> PII;

const int INF = 1e9 + 1;
void dijk(vector<PII>* adj, int* dist, int S) {
    priority_queue<PII, vector<PII>, greater<>> pQ;

    pQ.push({0, S});
    dist[S] = 0;
    while (pQ.size()) {
        int c, v;
        tie(c, v) = pQ.top();
        pQ.pop();
        if (dist[v] != c) continue;
        for (PII p : adj[v]) {
            int nc, nv;
            tie(nc, nv) = p;
            nc += c;
            if (dist[nv] <= nc) continue;
            pQ.push({nc, nv});
            dist[nv] = nc;
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int N, M, T, S, G, H, a, b, d, dGH = 0;
        int distS[2002], distG[2002], distH[2002];
        vector<PII> adj[2002];
        vector<int> trgs;

        fill(distS, distS + 2002, INF);
        fill(distG, distG + 2002, INF);
        fill(distH, distH + 2002, INF);
        cin >> N >> M >> T >> S >> G >> H;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
            if ((a == G && b == H) || (a == H && b == G)) dGH = d;
        }
        for (int i = 0; i < T; i++) {
            cin >> a;
            trgs.push_back(a);
        }
        dijk(adj, distS, S);
        dijk(adj, distG, G);
        dijk(adj, distH, H);
        sort(trgs.begin(), trgs.end());
        for (auto t : trgs) {
            int routeG = distS[G] + dGH + distH[t];
            int routeH = distS[H] + dGH + distG[t];
            if ((distS[t] == routeG) || (distS[t] == routeH)) cout << t << ' ';
        }
        cout << '\n';
    }
}