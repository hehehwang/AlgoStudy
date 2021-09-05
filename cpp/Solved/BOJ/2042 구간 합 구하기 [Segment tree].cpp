#include <bits/stdc++.h>
// 2042 구간 합 구하기 [Segment tree]
// https://www.acmicpc.net/problem/2042
using namespace std;
typedef long long ll;

int N, M, K, A[1'000'002];
ll tree[3'000'002];
ll init(int n, int st, int en) {
    if (st == en) return tree[n] = A[st];
    else
        return tree[n] = init(2 * n, st, (st + en) / 2) + init(2 * n + 1, (st + en) / 2 + 1, en);
};
ll query(int n, int st, int en, int l, int r) {
    if (r < st || en < l) return 0;
    if (l <= st && en <= r) return tree[n];
    return query(2 * n, st, (st + en) / 2, l, r) + query(2 * n + 1, (st + en) / 2 + 1, en, l, r);
}
void modify(int n, int st, int en, int index, ll diff) {
    if (index < st || en < index) return;
    tree[n] += diff;
    if (st != en) {
        modify(2 * n, st, (st + en) / 2, index, diff);
        modify(2 * n + 1, (st + en) / 2 + 1, en, index, diff);
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);
    ll a, b, c;
    M += K;
    while (M--) {
        cin >> a >> b >> c;
        if (a == 1) {
            modify(1, 1, N, b, c - A[b]);
            A[b] = c;
        } else
            cout << query(1, 1, N, b, c) << '\n';
    }
}