#include <bits/stdc++.h>
// 1956 운동
// https://www.acmicpc.net/problem/1956
using namespace std;
const int INF = 1e9 + 2;

int floyd[402][402], V, E, a, b, c, ans = INF;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < 402; i++)
        fill(floyd[i], floyd[i] + 402, INF);
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        floyd[a][b] = min(floyd[a][b], c);
    }
    for (int i = 1; i <= V; i++) floyd[i][i] = 0;
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for (int i = 1; i <= V; i++)
        for (int j = i + 1; j <= V; j++)
            ans = min(ans, floyd[i][j] + floyd[j][i]);
    cout << (INF <= ans ? -1 : ans);
}