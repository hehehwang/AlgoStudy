#include <bits/stdc++.h>
using namespace std;
// 4485 녹색 옷 입은 애가 젤다지 (Dijkstra)
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

const int mxN = 127, INF = 0x7f7f7f7f;
int board[mxN][mxN];
int minR[mxN][mxN];
priority_queue<TI3, vector<TI3>, greater<TI3>> pQ;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int idx = 1;
  while (1) {
    int N;
    cin >> N;
    if (!N) return 0;
    FOR(i, 0, N)
        FOR(j, 0, N) cin >> board[i][j];
    FOR(i, 0, N)
    fill(minR[i], minR[i] + N, INF);
    minR[0][0] = board[0][0];
    pQ.push({board[0][0], 0, 0});
    while (!pQ.empty()) {
      int vrp, vr, vc;
      tie(vrp, vr, vc) = pQ.top();
      pQ.pop();
      if (vrp != minR[vr][vc]) continue;
      FOR(k, 0, 4) {
        int nr = vr + dr[k];
        int nc = vc + dc[k];
        int nrp = vrp + board[nr][nc];
        if (nr < 0 || nc < 0 || N <= nr || N <= nc) continue;
        if (minR[nr][nc] <= nrp) continue;
        minR[nr][nc] = nrp;
        pQ.push({nrp, nr, nc});
      }
    }
    cout << "Problem " << idx << ": " << minR[N - 1][N - 1] << '\n';
    idx++;
  }
}