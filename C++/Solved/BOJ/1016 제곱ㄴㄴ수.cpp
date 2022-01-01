#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 1016 제곱 ㄴㄴ수
#define FOR(i, n, m) for(ll i=(n); i<(m); i++)
constexpr int LMT = 1000000;

vector<bool> sieve(LMT + 1, true);
ll Mi, Ma;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> Mi >> Ma;
	int rng = Ma - Mi + 1;
	ll iterMax = ll(sqrt(Ma));
	FOR(i, 2, iterMax + 1) {
		if (i != 2 && i % 2 == 0) continue;
		if (i != 3 && i % 3 == 0) continue;
		if (i != 5 && i % 5 == 0) continue;
		if (i != 7 && i % 7 == 0) continue;
		ll jg = i * i;
		FOR(mult, Mi / jg, (Ma / jg) + 1) {
			if (mult * jg < Mi) continue;
			if (Ma < mult * jg) continue;
			sieve[mult * jg - Mi] = false;
		}
	}
	int sm = 0;
	FOR(i, 0, rng) if (sieve[i]) sm++;
	cout << sm;
}