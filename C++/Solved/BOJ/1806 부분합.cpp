#include <bits/stdc++.h>
using namespace std;
// 1806 부분합
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, target;
	cin >> n >> target;
	int minLength = 100001;
	deque<int> series;
	int currSum = 0;
	FOR(t, 0, n) {
		int i;
		cin >> i;
		series.push_back(i);
		currSum += i;

		if (target <= currSum) {
			while (target <= currSum - series.front()) {
				currSum -= series.front();
				series.pop_front();
			}
			minLength = min(minLength, int(series.size()));
		}
	}
	if (minLength != 100001) cout << minLength;
	else cout << 0;
}