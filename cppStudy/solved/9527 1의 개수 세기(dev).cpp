#include <bits/stdc++.h>
#include <time.h>
using namespace std;
// 9527 1의 개수 세기
#define FOR(i, n, m) for(ll i=(n); i<(m); i++)
#define FORR(i, n, m) for(ll i=(n); (m)<i; i--)
using ll = long long;

ll cntNaive(ll a, ll b) {
	ll ans = 0;
	FOR(i, a, b + 1) ans += (ll)(__popcnt(i));
	return ans;
}

ll BinSeq(int n) {
	return n * (static_cast<ll>(1) << (n - 1));
}
ll findHead(ll n) {
	ll rtn = 0;
	while (n) {
		rtn += 1;
		n >>= 1;
	}
	return rtn;
}
ll cntAdv2(ll a, ll b) {
	a -= 1;
	ll rtnA = 0, rtnB = 0;
	while (a) {
		ll bh = findHead(a) - 1; // binary head
		ll cs = ((ll)1 << bh); // chunk size
		rtnA += BinSeq(bh);
		rtnA += (a - cs + 1); // peel-off
		a -= cs;
	}
	while (b) {
		ll bh = findHead(b) - 1; // binary head
		ll cs = ((ll)1 << bh); // chunk size
		rtnB += BinSeq(bh);
		rtnB += (b - cs + 1); // peel-off
		b -= cs;
	}
	return rtnB - rtnA;
}
ll cntAdv1(ll a, ll b) {
	a -= 1;
	int lA = findHead(a) - 1, lB = findHead(b) - 1;
	ll rtnA = BinSeq(lA), rtnB = BinSeq(lB);
	FOR(i, ((ll)(1) << lA), a + 1) { 
		rtnA += (ll)(__popcnt(i));
	}
	FOR(i, ((ll)(1) << lB), b + 1) rtnB += (ll)(__popcnt(i));
	return rtnB - rtnA;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	clock_t start, end;
	ll a, b;
	cin >> a >> b;
	start = clock();
	cout << cntNaive(a, b) << '\n';
	end = clock();
	cout << (double)(end - start) << "ms\n";
	start = clock();
	cout << cntAdv1(a, b) << '\n';
	end = clock();
	cout << (double)(end - start) << "ms\n";
	start = clock();
	cout << cntAdv2(a, b) << '\n';
	end = clock();
	cout << (double)(end - start) << "ms\n";
}