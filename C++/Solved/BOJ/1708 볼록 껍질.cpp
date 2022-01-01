#include <bits/stdc++.h>
using namespace std;
// 1708 볼록 껍질
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second
using ll = long long;
using PII = pair<int, int>;

int ptN;
PII pts[100002];
PII stk[100002];
int stkIdx;
ll ccw(PII p1, PII p2, PII p3) {
	return 1ll * (p2.X - p1.X) * (p3.Y - p1.Y) -
		1ll * (p2.Y - p1.Y) * (p3.X - p1.X);
}
bool cmp(PII v1, PII v2) {
	ll cc = ccw(pts[0], v1, v2);
	if (cc) return 0 < cc;
	return v1.X + v1.Y < v2.X + v2.Y;
}
PII subVec(PII v1, PII v2) {
	return { v1.X - v2.X, v1.Y - v2.Y };
}
bool _cmp(PII v1, PII v2) {
	int x1, x2, y1, y2;
	tie(x1, y1) = subVec(v1, pts[0]); 
	tie(x2, y2) = subVec(v2, pts[0]);
	if (1ll * y1 * x2 - 1ll * x1 * y2)
		return 1ll * y1 * x2 < 1ll * x1 * y2;
	else if (y1 - y2) return y1 < y2;
	return x1 < x2;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> ptN;
	int a, b;
	FOR(i, 0, ptN) {
		cin >> a >> b;
		pts[i] = { a, b };
	}
	sort(pts, pts + ptN);
	sort(pts + 1, pts + ptN, cmp);
	stk[0] = pts[0];
	stk[1] = pts[1];
	stkIdx = 1;
	FOR(idx, 2, ptN) {
		PII pt = pts[idx];
		while (1 <= stkIdx && ccw(stk[stkIdx - 1], stk[stkIdx], pt) <= 0) {
			stkIdx--;
		}
		stk[++stkIdx] = pt;
	}
	cout << stkIdx + 1;
	//cout << '\n';
	//FOR(i, 0, stkIdx+1) cout << stk[i].X << ' ' << stk[i].Y << '\n';
}