#include <bits/stdc++.h>
using namespace std;
// 9527 1의 개수 세기
#define FOR(i, n, m) for(ll i=(n); i<(m); i++)
#define FORR(i, n, m) for(ll i=(n); (m)<i; i--)
using ll = long long;

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

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	cout << cntAdv2(a, b);
}