#include <bits/stdc++.h>
using namespace std;
// 6118 숨바꼭질
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

vector<int> adj[20002];
int dist[20002];
vector<int> farest;
queue<int> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    FOR(i, 0, M) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Q.push(1);
    dist[1] = 1;
    int mxDist = 1;
    farest.push_back(1);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (auto nc : adj[cur]) {
            if (dist[nc]) continue;
            dist[nc] = dist[cur] + 1;
            if (mxDist < dist[nc]) {
                mxDist = dist[nc];
                farest = {};
            }
            farest.push_back(nc);
            Q.push(nc);
        }
    }
    sort(farest.begin(), farest.end());
    cout << farest[0] << ' ' << mxDist - 1 << ' ' << farest.size();
    // for (auto f : farest) cout << f << ' ';
}