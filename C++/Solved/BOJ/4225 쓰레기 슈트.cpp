#include <bits/stdc++.h>
using namespace std;
// 4225 쓰레기 슈트 [Naive]
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second
using PII = pair<int, int>;

PII pts[102];
double dist(PII &a, PII &b, PII &c) {
	return ((c.Y - a.Y) * (b.X - a.X) - (c.X - a.X) * (b.Y - a.Y)) / hypot(a.X - b.X, a.Y - b.Y);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tc = 0;
	while (1) {
		int n;
		double ans = 10e16;
		cin >> n;
		if (!n) break;
		FOR(i, 0, n) {
			int a, b;
			cin >> a >> b;
			pts[i] = { a, b };
		}
		FOR(i, 0, n) {
			FOR(j, i + 1, n) {
				double tMin = 0, tMax = 0;
				FOR(k, 0, n) {
					double v = dist(pts[i], pts[j], pts[k]);
					tMax = max(tMax, v);
					tMin = min(tMin, v);
					if (ans < (tMax - tMin)) break;
				}
				ans = min(ans, tMax - tMin);
			}
		}
		cout << fixed;
		cout.precision(2);
		cout << "Case " << ++tc << ": " << ans + 0.005 - 1e-12 << '\n';
	}
}