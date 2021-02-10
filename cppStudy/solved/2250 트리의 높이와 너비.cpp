#include <bits/stdc++.h>
using namespace std;
// 2250 트리의 높이와 너비
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int LMT = 10001;

int lc[LMT], rc[LMT];
pair<int, int> depth[LMT];
int n;
int r;
void inorder(int curr, int d) {
    if (curr == -1) return;
    inorder(lc[curr], d + 1);
    r++;
    if (!depth[d].first || r < depth[d].first) depth[d].first = r;
    if (!depth[d].second || depth[d].second < r) depth[d].second = r;
    inorder(rc[curr], d + 1);
}
int findRoot(void) {
    vector<bool> isR(n + 1, true);
    isR[0] = false;
    FOR(i, 0, LMT) if (lc[i] != -1) isR[lc[i]] = false;
    FOR(i, 0, LMT) if (rc[i] != -1) isR[rc[i]] = false;
    int i = 0;
    for (auto j : isR) {
        if (j) return i;
        i++;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    FOR(i, 0, n) {
        int p, l, r;
        cin >> p >> l >> r;
        lc[p] = l;
        rc[p] = r;
    }
    int mxWidth = 0, mxDepth = 0;
    inorder(findRoot(), 0);
    FOR(i, 0, n){
        auto d = depth[i];
        if (d.first + d.second == 0) break;
        int width = d.second - d.first + 1;
        if (mxWidth < width) {
            mxWidth = width;
            mxDepth = i;
        }
    }
    cout << mxDepth + 1 << ' ' << mxWidth;
}