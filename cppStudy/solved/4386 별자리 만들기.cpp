#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// 4386 별자리 만들기 [Prim]
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second
using pdd = pair<double, double>;

pdd stars[102];
bool chk[102];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pQ;
double distSq(pdd a, pdd b) {
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	FOR(i, 0, N) {
		double a, b;
		cin >> a >> b;
		stars[i] = { a,b };
	}
	double ans = 0;
	pdd curr = stars[0];
	chk[0] = true;
	FOR(i, 1, N) {
		pdd nxtStar = stars[i];
		pQ.push({ distSq(curr, nxtStar), i });
	}
	while (!pQ.empty()) {
		double dist;
		int curr;
		tie(dist, curr) = pQ.top(); pQ.pop();
		if (chk[curr]) continue;
		chk[curr] = true;
		ans += dist;
		FOR(nxt, 1, N) {
			if (chk[nxt]) continue;
			pQ.push({ distSq(stars[curr], stars[nxt]), nxt });
		}
	}
	cout << round(ans*100)/100;
}