#include <bits/stdc++.h>
using namespace std;
// 2252 줄 세우기
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int indeg[32002];
vector<int> preq[32002];
queue<int> nodeg;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        int a, b;
        cin >> a >> b;
        preq[a].push_back(b);
        indeg[b]++;
    }
    FOR(i, 1, n + 1) if (!indeg[i]) nodeg.push(i);
    while (!nodeg.empty()) {
        int v = nodeg.front(); nodeg.pop();
        cout << v << ' ';
        for (auto dest : preq[v]) {
            indeg[dest] --;
            if (!indeg[dest]) nodeg.push(dest);
        }
    }

}