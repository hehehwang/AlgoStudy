#include <bits/stdc++.h>
using namespace std;
// 4179 불!

const int maxN = 10E9;
int r, c;
string board[1002];
int fVis[1002][1002];
int jVis[1002][1002];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
queue<pair<int, int>> fQ, jQ;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	// initialize
	for (int i = 0; i < r; i++) {
		fill(fVis[i], fVis[i] + c, maxN);
		// fill(jVis[i], jVis[i] + c, 0);
	}

	// inputs
	for (int i = 0; i < r; i++) {
		cin >> board[i];
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				fQ.push({ i, j });
				fVis[i][j] = 1;
			}
			else if (board[i][j] == 'J') {
				jQ.push({ i, j });
				jVis[i][j] = 1;
			}
		}
	}

	// fire
	while (!fQ.empty()){
		pair<int, int> v = fQ.front(); fQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = v.first + dy[i];
			int nx = v.second + dx[i];
			if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
			if (board[ny][nx] == '#' || fVis[ny][nx] != maxN) continue;
			fVis[ny][nx] = fVis[v.first][v.second] + 1;
			fQ.push({ ny, nx });
		}
	}
	while (!jQ.empty()) {
		pair<int, int> v = jQ.front(); jQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = v.first + dy[i];
			int nx = v.second + dx[i];
			if (ny < 0 || r <= ny || nx < 0 || c <= nx) {
				cout << jVis[v.first][v.second];
				return 0;
			}
			if (board[ny][nx] == '#') continue;
			if (fVis[ny][nx] <= jVis[v.first][v.second] + 1) continue;
			if (jVis[ny][nx]) continue;
			jVis[ny][nx] = jVis[v.first][v.second] + 1;
			jQ.push({ ny, nx });
		}
	}

	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) cout << jVis[i][j] << '	';
	//	cout << '\n';
	//}
	//cout << '\n';

	cout << "IMPOSSIBLE";
}