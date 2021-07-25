#include <bits/stdc++.h>
using namespace std;
// 5214 환승
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int sN = 100001, tN = 1001;

vector<int> station[sN+tN];
int dist[sN+tN];
queue<int> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, M;
    cin >> N >> K >> M;
    FOR(i, 0, M) {
        FOR(j, 0, K) {
            int inp;
            cin >> inp;
            station[sN + i].push_back(inp);
            station[inp].push_back(sN + i);
        }
    }
    Q.push(1);
    dist[1] = 1;
    while (!Q.empty() && !dist[N]) {
        int cur = Q.front(); Q.pop();
        for (auto ncur : station[cur]) {
            if (dist[ncur]) continue;
            if (ncur < sN) dist[ncur] = dist[cur] + 1;
            else dist[ncur] = dist[cur];
            Q.push(ncur);
        }
    }
    if (dist[N]) cout << dist[N];
    else cout << -1;
}