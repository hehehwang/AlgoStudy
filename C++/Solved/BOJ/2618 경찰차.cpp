#include <bits/stdc++.h>
// 2618 경찰차
// https://www.acmicpc.net/problem/2618
using namespace std;
using PII = pair<int, int>;
const int INF = 1e9;

int state[1002][1002], R, incs;
PII incidents[1002], pre[1002][1002];
int drive(int A, int B) {
    PII a = incidents[A], b = incidents[B];
    if (!A) a = {1, 1};
    if (!B) b = {R, R};
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void move_police(int a, int b, int x) {
    // state(a, b) to (x, b) or (a, x)
    int prev_state = state[a][b];
    int pA = prev_state + drive(a, x);  // police A moves
    int pB = prev_state + drive(x, b);  // police B moves
    if (pA < state[x][b]) {
        state[x][b] = pA;
        pre[x][b] = {a, b};
    }
    if (pB < state[a][x]) {
        state[a][x] = pB;
        pre[a][x] = {a, b};
    }
}
int which_car(PII incident) {
    auto [a, b] = incident;
    if (a < b) return 2;
    else
        return 1;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> incs;
    for (int i = 0; i <= incs; i++) fill(state[i], state[i] + incs + 1, INF);
    state[0][0] = 0;
    for (int i = 1; i <= incs; i++) {
        cin >> incidents[i].first >> incidents[i].second;
        for (int k = 0; k < i; k++) {
            int a = i - 1, b = k;
            if ((a || b) && a == b) continue;
            move_police(a, b, i);
            move_police(b, a, i);
        }
    }
    int ans = INF;
    PII to_prev = {0, 0};
    vector<int> path;

    for (int r = 0; r <= incs; r++) {
        for (int c = 0; c <= incs; c++) {
            cout << state[r][c] << "\t";
        }
        cout << "\n";
    }
    for (int k = 0; k <= incs; k++) {
        int r = k, c = incs;
        if (state[r][c] < ans) {
            ans = state[r][c];
            to_prev = {r, c};
        }
        swap(r, c);
        if (state[r][c] < ans) {
            ans = state[r][c];
            to_prev = {r, c};
        }
    }
    cout << ans << "\n";
    while (to_prev.first || to_prev.second) {
        path.push_back(which_car(to_prev));
        to_prev = pre[to_prev.first][to_prev.second];
    }
    reverse(path.begin(), path.end());
    for (int a : path) cout << a << "\n";
}