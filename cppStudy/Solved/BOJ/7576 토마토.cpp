#include <bits/stdc++.h>
// 7576 토마토
// https://www.acmicpc.net/problem/7576
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using namespace std;

int R, C;
int board[1002][1002];
int vis[1002][1002];
queue<pair<int, int>> Q;
int main(void)
{
   ios::sync_with_stdio(0);
   cin.tie(0);

   cin >> C >> R;
   FOR(i, 0, R) {
      FOR(j, 0, C) {
         cin >> board[i][j];
         if (board[i][j] == 1) {
            Q.push({ i, j });
            vis[i][j] = 1;
         }
         else if (!board[i][j]) vis[i][j] = -1;
      }
   }

   while (!Q.empty()) {
      int vr, vc;
      tie(vr, vc) = Q.front();
      Q.pop();
      FOR(k, 0, 4) {
         int nr = vr + "1012"[k] - '1';
         int nc = vc + "2101"[k] - '1';
         if (nr < 0 || nc < 0 || R <= nr || C <= nc)
            continue;
         if (0 <= vis[nr][nc]) continue;
         vis[nr][nc] = vis[vr][vc] + 1;
         Q.push({ nr, nc });
      }
   }
   bool F = true;
   int mxVis = 0;
   FOR(i, 0, R) {
      FOR(j, 0, C) {
         if (vis[i][j] == -1) {
            F = false;
            break;
         }
         mxVis = max(mxVis, vis[i][j]);
      }
   }
   if (F)
      cout << mxVis - 1;
   else
      cout << -1;
}