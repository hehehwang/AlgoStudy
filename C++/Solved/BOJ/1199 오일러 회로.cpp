#include <bits/stdc++.h>
// 1199 오일러 회로
// https://www.acmicpc.net/problem/1199
using namespace std;

int N, A[1010][1010], t;
stack<pair<int, int>> edges[1010];
vector<bool> chk;
void printEularCircuit(int node) {
    while (1) {
        // 반대편에서 사용한 경우 감지
        while (edges[node].size() && chk[edges[node].top().second])
            edges[node].pop();
        if (edges[node].empty()) break;
        int nv, id;
        tie(nv, id) = edges[node].top();
        edges[node].pop();
        chk[id] = 1;
        printEularCircuit(nv);
    }
    cout << node << ' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int id = 0;
    for (int i = 1; i <= N; i++) {
        int deg = 0;
        for (int j = 1; j <= N; j++) {
            cin >> t;
            if (i < j) {
                for (int k = 0; k < t; k++) {
                    edges[i].push({j, ++id});
                    edges[j].push({i, id});
                }
            }
            deg += t;
        }
        if (deg % 2) {
            cout << -1;
            return 0;
        }
    }
    chk.resize(id + 1);
    printEularCircuit(1);
}