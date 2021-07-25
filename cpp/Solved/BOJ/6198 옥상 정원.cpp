#include <bits/stdc++.h>
using namespace std;
// 6198 옥상 정원
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

int N;
long long cnt;
queue<int> bld;
stack<int> stk;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	FOR(i, 0, N) {
		int v;
		cin >> v;
		bld.push(v);
	}

	while (1) {
		if (stk.empty()) {
			stk.push(bld.front());
			bld.pop();
		}
		if (bld.empty()) break;
		if (bld.front() < stk.top()) {
			cnt += stk.size();
			stk.push(bld.front());
			bld.pop();
		}
		else stk.pop();
	}
	cout << cnt;
}