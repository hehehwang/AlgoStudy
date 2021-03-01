#include <bits/stdc++.h>
using namespace std;
// 4196 친구 네트워크
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

map<string, string> grpHead;
map<string, int> fCnt;
string find(string v) {
	if (!grpHead[v].compare(v)) return v;
	grpHead[v] = find(grpHead[v]);
	return grpHead[v];
}
void unite(string a, string b) {
	if (find(a) != find(b)) fCnt[find(a)] += fCnt[find(b)];
	grpHead[grpHead[b]] = grpHead[a];
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	FOR(tt, 0, T) {
		grpHead = {};
		fCnt = {};
		int N;
		cin >> N;
		FOR(i, 0, N) {
			string a, b;
			cin >> a >> b;
			if (a < b) swap(a, b);
			if (grpHead.find(a) == grpHead.end()) {
				grpHead[a] = a;
				fCnt[a] = 1;
			}
			if (grpHead.find(b) == grpHead.end()) {
				grpHead[b] = b;
				fCnt[b] = 1;
			}
			unite(a, b);
			cout << fCnt[find(a)] << '\n';
		}
	}
}