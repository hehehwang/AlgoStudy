#include <bits/stdc++.h>
// 20040 사이클 게임
// https://www.acmicpc.net/problem/20040
using namespace std;

int grpNo[500002], N, M;
int find(int v) {
    if (grpNo[v] == v) return v;
    grpNo[v] = find(grpNo[v]);
    return grpNo[v];
}
void unite(int a, int b) {
    if (b < a) swap(a, b);
    grpNo[find(b)] = find(a);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i <= N; i++) grpNo[i] = i;
    int a, b;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i;
            return 0;
        }
        unite(a, b);
    }
    cout << 0;
}