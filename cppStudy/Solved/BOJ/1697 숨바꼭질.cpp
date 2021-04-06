#include <bits/stdc++.h>
using namespace std;
// 1697 숨바꼭질

#define LIM 200000
int s, b;
int vis[LIM];
queue<int> Q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> b;
	vis[s] = 1;
	Q.push(s);

	while (!vis[b]) {
		auto v = Q.front(); Q.pop();
		if (v + 1 < LIM && !vis[v + 1]) {
			vis[v + 1] = vis[v] + 1;
			Q.push(v + 1);
		}
		if (0 <= v - 1 && !vis[v - 1]) {
			vis[v - 1] = vis[v] + 1;
			Q.push(v - 1);
		}
		if (2 * v < LIM && !vis[2 * v]) {
			vis[2 * v] = vis[v] + 1;
			Q.push(2 * v);
		}
	}
	cout << vis[b] - 1;
}

