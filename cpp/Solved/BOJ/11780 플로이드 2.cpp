#include <bits/stdc++.h>
using namespace std;
// 11780 플로이드 2

int floyd[101][101];
int nxt[101][101];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    n++;
    for (int j = 0; j < m; j++) {
        int a, b, c;
        cin >> a >> b >> c;
        floyd[a][b] = (floyd[a][b]) ? min(floyd[a][b], c) : c;
        nxt[a][b] = b;
    }
    for (int k = 1; k < n; k++) {
        for (int i = 1; i < n; i++) {
            if (i == k) continue;
            for (int j = 1; j < n; j++) {
                if (j == k) continue;
                if (i == j) continue;
                int bypass = floyd[i][k] + floyd[k][j];
                if (floyd[i][j] && floyd[i][k] && floyd[k][j]) {
                    if (bypass < floyd[i][j]) {
                        floyd[i][j] = bypass;
                        nxt[i][j] = nxt[i][k];
                    }
                } else if (floyd[i][k] && floyd[k][j]) {
                    floyd[i][j] = bypass;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << floyd[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> route = {i};
            while (1) {
                if (route.back() == j) {
                    cout << route.size() << ' ';
                    for (auto r : route) cout << r << ' ';
                    cout << '\n';
                    break;
                } else if (route.back() == 0) {
                    cout << 0 << '\n';
                    break;
                }
                route.push_back(nxt[route.back()][j]);
            }
        }
    }
}