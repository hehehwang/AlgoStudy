#include <bits/stdc++.h>
using namespace std;
// 2150 Strongly Connected Component
// https://www.acmicpc.net/problem/2150
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

const int MXV = 10'002;
int V, E;
int a, b;
vector<int> after[MXV];
vector<int> before[MXV];
vector<vector<int>> scc(MXV);
vector<bool> vis(MXV);
stack<int> stk;
void dfs(int v){
    vis[v] = true;
    for(int nv: after[v]){
        if (vis[nv])
            continue;
        dfs(nv);
    }
    stk.push(v);
}
void rDfs(int v, int cNo){
    vis[v] = true;
    scc[cNo].push_back(v);
    for(int nv: before[v]){
        if (vis[nv])
            continue;
        rDfs(nv, cNo);
    }
}
bool cmp(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0];
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    FOR(i, 0, E){
        cin >> a >> b;
        after[a].push_back(b);
        before[b].push_back(a);
    }
    FOR(i, 1, V+1){
        if (vis[i])
            continue;
        dfs(i);
    }
    fill(vis.begin(), vis.begin() + V + 1, false);
    int compN = 0;
    while(!stk.empty()){
        int v = stk.top();
        stk.pop();
        if (vis[v])
            continue;
        rDfs(v, compN);
        sort(scc[compN].begin(), scc[compN].end());
        scc[compN].push_back(-1);
        compN++;
    }
    sort(scc.begin(), scc.begin()+compN, cmp);
    cout << compN << '\n';
    FOR(i, 0, compN){
        for(auto v: scc[i])
            cout << v << ' ';
        cout << '\n';
    }
}