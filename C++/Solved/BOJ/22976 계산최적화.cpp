#include <bits/stdc++.h>
// 22976 계산 최적화
// https://www.acmicpc.net/problem/22976
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PLL;
const int MOD = 1e9 + 7;

int N, Q;
PLL init(vector<PLL> &A, vector<PLL> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = A[start];
    else {
        PLL left, right;
        ll a1, b1, a2, b2;
        tie(a1, b1) = init(A, tree, node * 2, start, (start + end) / 2);
        tie(a2, b2) = init(A, tree, node * 2 + 1, (start + end) / 2 + 1, end);

        return tree[node] = {(a1 * a2) % MOD, (a2 * b1 + b2) % MOD};
    }
}
void traceBack(vector<PLL> &tree, int node) {
    if (!node) return;
    ll a1, b1, a2, b2;
    tie(a1, b1) = tree[node * 2];
    tie(a2, b2) = tree[node * 2 + 1];
    tree[node] = {(a1 * a2) % MOD, (a2 * b1 + b2) % MOD};
    traceBack(tree, node / 2);
}
void update(vector<PLL> &tree, int node, int start, int end, int index, PLL value) {
    if (start == end) {
        tree[node] = value;
        traceBack(tree, node / 2);
    } else {
        if ((start + end) / 2 < index)
            update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
        else
            update(tree, node * 2, start, (start + end) / 2, index, value);
    }
}
PLL getPair(char op, int k) {
    if (op == '+') return {1, k};
    else
        return {k, 0};
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    vector<PLL> A(N);
    int tree_size = 1 << ((int)ceil(log2(N)) + 1);
    vector<PLL> tree(tree_size);
    char op;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> op >> k;
        A[i] = getPair(op, k);
    }
    init(A, tree, 1, 0, N - 1);
    for (int i = 0; i < Q; i++) {
        int No;
        cin >> No >> op >> k;
        No--;
        PLL v;
        update(tree, 1, 0, N - 1, No, getPair(op, k));
        cout << tree[1].second << '\n';
    }
}