#include <bits/stdc++.h>
// 1572 중앙값
// https://www.acmicpc.net/problem/1572
using namespace std;
const int MXN = 65536;

vector<int> tree(MXN * 4);
long long ans;
int N, K, x;
void update(int node, int st, int en, int idx, int diff) {
    if (idx < st || en < idx) return;
    tree[node] += diff;
    if (st == en) return;
    int mid = (st + en) / 2;
    update(node * 2, st, mid, idx, diff);
    update(node * 2 + 1, mid + 1, en, idx, diff);
}
int query(int node, int st, int en, int val) {
    if (st == en) return st;
    int left = tree[node * 2], mid = (st + en) / 2;
    if (left >= val)
        return query(node * 2, st, mid, val);
    else
        return query(node * 2 + 1, mid + 1, en, val - left);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    queue<int> q;
    for (int i = 0; i < K - 1; i++) {
        cin >> x;
        update(1, 0, MXN, x, 1);
        q.push(x);
    }
    for (int i = K; i <= N; i++) {
        cin >> x;
        update(1, 0, MXN, x, 1);
        q.push(x);
        ans += query(1, 0, MXN, (K + 1) / 2);
        update(1, 0, MXN, q.front(), -1);
        q.pop();
    }
    cout << ans;
}