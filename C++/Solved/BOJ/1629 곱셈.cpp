#include <bits/stdc++.h>
using namespace std;
// 1629 곱셈

using ll = long	long;

ll MOD;

ll pwr(ll a, ll b) {
	if( b == 1) return a % MOD;
	ll val = pwr(a, b / 2); val = (val * val)% MOD;
	if (b % 2) return (val * a) % MOD;
	return val;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b >> MOD;
	cout << pwr(a, b);
}
