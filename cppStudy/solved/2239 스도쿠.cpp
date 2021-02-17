#include <bits/stdc++.h>
using namespace std;
// 2239 스도쿠
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using TI3 = tuple<int, int, int>;
using PII = pair<int, int>;

int board[9][9];
vector<PII> zeros;
vector<int> possibleNums(int r, int c) {
	vector<bool> chk(10, true);
	FOR(i, 0, 9) {
		chk[board[r][i]] = false;
		chk[board[i][c]] = false;
	}
	FOR(i, (r / 3) * 3, (r / 3) * 3 + 3) {
		FOR(j, (c / 3) * 3, (c / 3) * 3 + 3) {
			chk[board[i][j]] = false;
		}
	}
	vector<int> rtn;
	FOR(i, 1, 10) if (chk[i]) rtn.push_back(i);
	return rtn;
}
bool findSudoku(int i) {
	if (i == zeros.size()) return true;
	PII z = zeros[i];
	vector<int> lst = possibleNums(z.first, z.second);
	if (lst.empty()) return false;
	for (auto l : lst) {
		board[z.first][z.second] = l;
		if (findSudoku(i + 1)) return true;
		board[z.first][z.second] = 0;
	}
	return false; // DoubleFree error
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(i, 0, 9) {
		string ss;
		cin >> ss;
		FOR(j, 0, 9) {
			board[i][j] = int(ss[j]-48);
			if (!board[i][j]) zeros.push_back({ i, j });
		}
	}
	findSudoku(0);
	FOR(i, 0, 9) {
		FOR(j, 0, 9) cout << board[i][j];
		cout << '\n';
	}
}