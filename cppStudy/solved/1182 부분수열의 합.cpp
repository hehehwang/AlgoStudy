#include <bits/stdc++.h>
using namespace std;
// 1182 부분수열의 합
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int n, s;
int nums[22];
bool isUsed[22];
int cnt;
void seq(int sums, int used, int idx) {
	if (sums == s) cnt++;
	else if (used == n) return;
	FOR(i, idx, n) {
		if (isUsed[i]) continue;
		isUsed[i] = true;
		seq(sums + nums[i], used + 1, i);
		isUsed[i] = false;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	FOR(i, 0, n) cin >> nums[i];
	seq(0, 0, 0);
	if (s) cout << cnt;
	else cout << cnt - 1;
}