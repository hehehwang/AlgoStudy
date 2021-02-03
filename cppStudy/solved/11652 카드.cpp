#include <bits/stdc++.h>

using namespace std;
// 11652 카드
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
#define X first
#define Y second

using ll = long long;
int N;
ll arr[100003];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	FOR(i, 0, N) cin >> arr[i];
	sort(arr, arr + N);

	int mxCnt = 0, cnt = 0;
	ll mxNum = arr[0];
	FOR(i, 0, N+1) {
		if (i == 0) continue;
		if (arr[i] == arr[i - 1]) cnt++;
		else {
			if (mxCnt < cnt || (mxCnt == cnt && arr[i-1] < mxNum)) {
				mxCnt = cnt;
				mxNum = arr[i - 1];
			}
			cnt = 0;
		}
	}
	cout << mxNum;
}