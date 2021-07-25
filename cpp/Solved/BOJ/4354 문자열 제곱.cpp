#include <bits/stdc++.h>
using namespace std;
// 4354 문자열 제곱
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		string sss;
		cin >> sss;
		if (sss == ".") break;
		int L = sss.size();
		vector<int> ff(L, 0);
		int begin = 1, matched = 0;
		while (begin + matched < L) {
			if (sss[begin + matched] == sss[matched]) {
				matched++;
				ff[begin + matched-1] = matched;
			}
			else {
				if (!matched) matched = 1;
				begin += matched - ff[matched-1];
				matched = ff[matched-1];
			}
		}
		int v = L - ff[L-1];
		if (L % v) cout << 1 << '\n';
		else cout << L/(v) << '\n';
	}
}