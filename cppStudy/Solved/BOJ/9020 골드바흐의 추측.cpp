#include <bits/stdc++.h>
// 9020 골드바흐의 추측
// https://www.acmicpc.net/problem/9020
using namespace std;

const int MXN = 10'002;
vector<bool> seive(MXN, 1);
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i * i < MXN; i++) {
        if (!seive[i]) continue;
        for (int j = i * i; j <= MXN; j += i) seive[j] = false;
    }

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int c;
        cin >> c;
        for (int a = c / 2; 0 < a; a--) {
            int b = c - a;
            if (seive[a] && seive[b]) {
                cout << a << ' ' << b << '\n';
                break;
            }
        }
    }
}