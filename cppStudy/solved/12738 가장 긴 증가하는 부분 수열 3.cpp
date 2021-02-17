#include <bits/stdc++.h>
using namespace std;
// 12738 가장 긴 증가하는 부분 수열 3
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> lis;
	lis.push_back(-1000000001);
	FOR(i, 1, n+1) {
		int num;
		cin >> num;
		if (lis.back() < num) lis.push_back(num);
		else *lower_bound(lis.begin(), lis.end(), num) = num;
	}
	// for (auto v : lis) cout << v << ' ';
	cout << lis.size() - 1;
}