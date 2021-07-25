#include <bits/stdc++.h>
using namespace std;
// 14002 가장 긴 증가하는 부분 수열 4
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;
const int LIM = 1002;

int nums[LIM];
int order[LIM];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> lis, ans;
	lis.push_back(0);
	FOR(i, 1, n + 1) {
		int num;
		cin >> num;
		nums[i] = num;
		if (lis.back() < num) {
			lis.push_back(num);
			order[i] = lis.size() - 1;
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), num);
			*it = num;
			order[i] = it - lis.begin();
		}
	}
	int idx = lis.size() - 1;
	for (int i = n; i > 0; i--) {
		if (order[i] == idx) {
			ans.push_back(nums[i]);
			idx--;
		}
	}
	cout << lis.size() - 1;
	cout << '\n';
	for (auto it = ans.rbegin(); it != ans.rend(); it++) 
		cout << *it << ' ';
}