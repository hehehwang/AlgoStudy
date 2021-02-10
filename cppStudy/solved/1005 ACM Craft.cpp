#include <bits/stdc++.h>
using namespace std;
// 1005 ACM Craft
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int LMT = 1002;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR(t, 0, tc) {
        int tC[LMT] = {};
        vector<int> preQ[LMT];
        vector<int> proQ[LMT];
        queue<int> noDeg;
        int dp[LMT] = {};
        int inDeg[LMT] = {};
        int n, m;
        cin >> n >> m;
        FOR(i, 1, n+1) cin >> tC[i];
        FOR(i, 0, m) {
            int a, b;
            cin >> a >> b;
            proQ[a].push_back(b);
            preQ[b].push_back(a);
            inDeg[b] ++;
        }
        int tgt;
        cin >> tgt;
        FOR(i, 1, n + 1) if (!inDeg[i]) noDeg.push(i);
        while (1) {
            int v = noDeg.front(); noDeg.pop();
            if (preQ[v].empty()) dp[v] = tC[v];
            else {
                int mxV = 0;
                for (auto pV : preQ[v]) mxV = max(mxV, dp[pV]);
                dp[v] = mxV + tC[v];
            }
            if (v == tgt) break;
            for (auto nv : proQ[v]) {
                inDeg[nv] -= 1;
                if (!inDeg[nv]) noDeg.push(nv);
            }
        }
        cout << dp[tgt] << '\n';
    }
}