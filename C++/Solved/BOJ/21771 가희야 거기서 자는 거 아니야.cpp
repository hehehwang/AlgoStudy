#include <bits/stdc++.h>
// 21771 가희야 거기서 자는 거 아니야
// https://www.acmicpc.net/problem/21771
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using namespace std;

int R, C, Rg, Rp, Cg, Cp, cnt;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> Rg >> Cg >> Rp >> Cp;
    char c;
    FOR(i, 0, R)
    FOR(j, 0, C) {
        cin >> c;
        if (c == 'P') cnt++;
    }
    cout << int(cnt != Rp * Cp);
}