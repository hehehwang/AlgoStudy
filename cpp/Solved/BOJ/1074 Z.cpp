#include <bits/stdc++.h>
using namespace std;
// 1074 Z

int zf(int n, int r, int c) {
	if (n == 1) return 2 * r + c;
	int MID = (1 << (n - 1));
	if (r < MID && c < MID) return zf(n - 1, r, c);
	else if (r < MID && MID <= c) return zf(n - 1, r, c - MID) + (MID * MID);
	else if (MID <= r && c < MID) return zf(n - 1, r - MID, c) + (MID * MID) * 2;
	return zf(n - 1, r - MID, c - MID) + (MID * MID) * 3;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	cout << zf(n, r, c);
}