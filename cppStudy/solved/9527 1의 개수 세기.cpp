#include <bits/stdc++.h>
using namespace std;
// 9527 1의 개수 세기
using ll = long long;

ll binSeq(int n) {
	return n * (1ll << (n - 1));
}
ll findHead(ll n) {
	ll rtn = 0;
	while (n) {
		rtn += 1;
		n >>= 1;
	}
	return rtn;
}
ll cntOne(ll n) {
	ll rtn = 0;
	while (n) {
		ll bh = findHead(n) - 1; // binary head
		ll cs = (1ll << bh); // chunk size
		rtn += binSeq(bh);
		rtn += (n - cs + 1);
		n -= cs;
	}
	return rtn;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	cout << cntOne(b) - cntOne(a - 1);
}