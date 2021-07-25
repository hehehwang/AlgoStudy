#include <bits/stdc++.h>
using namespace std;
// 2467 용액
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

vector<int> nums;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	FOR(i, 0, n) {
		int v;
		cin >> v;
		nums.push_back(v);
	}
	sort(nums.begin(), nums.end());
	auto pt1 = nums.begin(), pt2 = nums.end()-1;
	auto minPt1 = pt1, minPt2 = pt2;
	int minV = abs(*pt2 + *pt1);
	while (1) {
		if (abs(*pt1 + *(pt2 - 1)) < abs(*(pt1 + 1) + *pt2)) {
			pt2 -= 1;
		}
		else pt1 += 1;
		if (pt1 == pt2) break;
		if (abs(*pt1 + *pt2) < minV) {
			minV = abs(*pt1 + *pt2);
			minPt1 = pt1;
			minPt2 = pt2;
		}
	}
	cout << *minPt1 << ' ' << *minPt2;
}