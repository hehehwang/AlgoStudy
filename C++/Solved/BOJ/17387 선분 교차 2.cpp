// 17387 선분 교차 2
// https://www.acmicpc.net/problem/17387
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int ccw(pii p0, pii p1, pii p2) {
  ll v = 1ll * (p1.X - p0.X) * (p2.Y - p1.Y) - 1ll * (p2.X - p1.X) * (p1.Y - p0.Y);
  if (v > 0) return 1;
  if (v < 0) return -1;
  return 0;
}
bool line_crossed(pii p1, pii p2, pii p3, pii p4) {
  int l1l2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
  int l3l4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);
  if (l1l2 == 0 && l3l4 == 0) {
    if (p2 < p1) swap(p1, p2);
    if (p4 < p3) swap(p3, p4);
    return p3 <= p2 && p1 <= p4;
  }
  return l1l2 <= 0 && l3l4 <= 0;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  if (line_crossed({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}))
    cout << 1;
  else
    cout << 0;
}