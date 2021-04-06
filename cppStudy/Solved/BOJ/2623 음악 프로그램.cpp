#include <bits/stdc++.h>
using namespace std;
// 2623 음악 프로그램
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int indeg[1002];
vector<int> preq[1002];
vector<int> res;
queue<int> nodeg;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int k, a, b = 0;
        cin >> k;
        if (k) cin >> a;
        FOR(j, 0, k-1) {
            cin >> b;
            preq[a].push_back(b);
            indeg[b]++;
            a = b;
        }
    }
    FOR(i, 1, n + 1) if (!indeg[i]) nodeg.push(i);
    while (!nodeg.empty()) {
        int v = nodeg.front(); nodeg.pop();
        res.push_back(v);
        for (auto nv : preq[v]) {
            indeg[nv] --;
            if (!indeg[nv]) nodeg.push(nv);
        }
    }
    if (res.size() != n) cout << 0;
    else for (auto r : res) cout << r << '\n';
}