#include <bits/stdc++.h>
// 11967 불켜기
// https://www.acmicpc.net/problem/11967
using namespace std;
using PII = pair<int, int>;

int N, M, ans = 1;
bool rooms[102][102];
vector<PII> switches[102][102], turnOn;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    rooms[1][1] = true;
    int x, y, a, b;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }
    while (1) {
        bool visited[102][102] = {};
        queue<PII> q;
        q.push({1, 1});
        visited[1][1] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto sw : switches[r][c])
                turnOn.push_back(sw);
            switches[r][c].clear();
            for (int k = 0; k < 4; k++) {
                int nr = r + "1102"[k] - '1';
                int nc = c + "2011"[k] - '1';
                if (nr <= 0 || nc <= 0 || nr > N || nc > M || visited[nr][nc] || !rooms[nr][nc])
                    continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        if (turnOn.empty()) break;
        for (auto [r, c] : turnOn) {
            if (rooms[r][c]) continue;
            rooms[r][c] = true;
            ans++;
        }
        turnOn.clear();
    }
    cout << ans;
}