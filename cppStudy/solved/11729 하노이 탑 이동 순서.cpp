#include <bits/stdc++.h>
using namespace std;
// 11729 하노이 탑 이동 순서

void hannoi(int n, int f, int t) {
	if (n == 1) {
		cout << f << ' ' << t << '\n';
		return;
	}
	int k = 6 - f - t;
	hannoi(n - 1, f, k);
	hannoi(1, f, t);
	hannoi(n - 1, k, t);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v;
	cin >> v;
	// long long cnt = pow(2, v);
	// cout << cnt - 1 << '\n';
	cout << (1 << v) - 1 << '\n';
	hannoi(v, 1, 3);
}