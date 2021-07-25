#include <bits/stdc++.h>
using namespace std;
// 1717 집합의 표현
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int grpNo[1000002];
int find(int v) {
	if (v == grpNo[v]) return v;
	grpNo[v] = find(grpNo[v]);
	return grpNo[v];
}
void unite(int a, int b) {
	if (b < a) swap(a, b);
	grpNo[find(b)] = find(a);
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	FOR(i, 0, N + 1) grpNo[i] = i;
	FOR(i, 0, M) {
		int c, a, b;
		cin >> c >> a >> b;
		if (c) {
			if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
		else unite(a, b);
	}
}