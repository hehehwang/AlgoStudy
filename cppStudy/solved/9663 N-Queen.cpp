#include <bits/stdc++.h>
using namespace std;
// 9663 N-Queen

#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int n;
int board[20][20];
int cnt;
int isUsedX[40], isUsedD1[40], isUsedD2[40];

void nq(int i) {
	if (i == n) {
		cnt++;
		return;
	}
	FOR(j, 0, n) {
		if (isUsedX[j]) continue;
		if (isUsedD1[i + j]) continue;
		if (isUsedD2[i - j + n - 1]) continue;
		board[i][j] = 1;
		isUsedX[j] = 1;
		isUsedD1[i + j] = 1;
		isUsedD2[i - j + n - 1] = 1;
		nq(i + 1);
		board[i][j] = 0;
		isUsedX[j] = 0;
		isUsedD1[i + j] = 0;
		isUsedD2[i - j + n - 1] = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	nq(0);
	cout << cnt;
}