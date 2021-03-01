#include <bits/stdc++.h>
using namespace std;
// 2166 다각형의 면적
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second
using ll = long long;
using Pll = pair<ll, ll>;

Pll coord[10003];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	FOR(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		coord[i] = { a, b };
	}
	coord[n] = coord[0];
	ll area = 0;
	FOR(i, 0, n) {
		area += coord[i].X * coord[i + 1].Y - coord[i].Y * coord[i + 1].X;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(area / 2.0);
}