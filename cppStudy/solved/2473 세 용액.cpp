#include <bits/stdc++.h>
using namespace std;
// 2473 세 용액
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;
using ll = long long;

vector<ll> nums;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	FOR(i, 0, n) {
		ll v;
		cin >> v;
		nums.push_back(v);
	}
	sort(nums.begin(), nums.end());
	ll minV = abs(nums[0]+nums[1]+nums[2]);
	auto minP1 = nums.begin(), minP2 = minP1+1, minP3 = minP1+2;
	for (auto p1 = nums.begin(); p1 < nums.end()-2; p1++) {
		auto p2 = p1 + 1, p3 = nums.end() - 1;
		while (1) {
			if (p2 == p3) break;
			if (abs(*p1 + *p2 + *p3) < minV) {
				minP1 = p1;
				minP2 = p2;
				minP3 = p3;
				minV = abs(*p1 + *p2 + *p3);
			}
			if (!minV) break;
			if (abs(*p1 + *(p2 + 1) + *p3) < abs(*p1 + *p2 + *(p3 - 1))) p2 += 1;
			else p3 -= 1;
		}
		if (!minV) break;
	}
	cout << *minP1 << ' ' << *minP2 << ' ' << *minP3;
}