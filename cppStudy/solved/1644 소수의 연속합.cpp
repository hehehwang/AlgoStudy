#include <bits/stdc++.h>
using namespace std;
// 1644 소수의 연속합
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> pN;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=2; i*i<MXN; i++){
		if (!seive[i]) continue;
		for (int j = i * i; j < MXN; j += i) seive[j] = false;
	}
	FOR(i, 2, MXN) if (seive[i]) pN.push_back(i);
	pN.push_back(0);
	int target, s = 0, e = 1, ans = 0, tmpSum = pN[0];
	cin >> target;
	while (1) {
		if (tmpSum == target) {
			ans++;
		}
		if (tmpSum <= target) {
			e++;
			tmpSum += pN[e-1];
		}
		if (target < tmpSum) {
			tmpSum -= pN[s];
			s++;
		}
		if (e == pN.size()) break;
	}
	cout << ans;
}