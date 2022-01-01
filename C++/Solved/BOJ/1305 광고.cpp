#include <bits/stdc++.h>
using namespace std;
// 1305 광고
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int L;
	cin >> L;
	string S;
	cin >> S;
	vector<int> ff(L, 0);
	int begin = 1, matched = 0;
	while (begin + matched < L) {
		if (S[begin + matched] == S[matched]) {
			matched++;
			ff[begin + matched - 1] = matched;
		}
		else {
			if (!matched) matched++;
			begin += matched - ff[matched-1];
			matched = ff[matched - 1];
		}
	}
	cout << L - ff[L - 1];
}