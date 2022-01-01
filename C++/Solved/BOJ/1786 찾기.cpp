#include <bits/stdc++.h>
using namespace std;
// 1786 찾기
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

string H, N;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	getline(cin, H);
	getline(cin, N);
	
	int begin = 1, matched = 0;
	int nL = N.length(), hL = H.length();
	vector<int> p(nL+1, 0);
	while (begin + matched < nL) {
		if (N[begin + matched] == N[matched]) {
			matched++;
			p[begin + matched - 1] = matched;
		}
		else {
			if (!matched) matched = 1;
			begin += matched - p[matched - 1];
			matched = p[matched - 1];
		}
	}
	int cnt = 0;
	vector<int> pos;
	begin = 0;
	matched = 0;
	while (begin <= hL-nL) {
		if (H[begin+matched] == N[matched] && matched < nL){
			matched++;
			if (matched == nL) {
				cnt++;
				pos.push_back(begin+1);
			}
		}
		else {
			if (!matched) matched = 1;
			begin += matched - p[matched - 1];
			matched = p[matched - 1];
		}
	}
	cout << cnt << '\n';
	for (int v : pos) cout << v << ' ';
}