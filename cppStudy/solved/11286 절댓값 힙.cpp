#include <bits/stdc++.h>
using namespace std;
// 11286 절댓값 힙
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using ll = long long;

priority_queue<ll, vector<ll>, greater<>> pQ;
priority_queue<ll, vector<ll>, less<>> nQ;
int getValue() {
	int rtn;
	if (pQ.empty() && nQ.empty()) rtn = 0;
	else if (pQ.empty()) {
		rtn = nQ.top(); nQ.pop();
	}
	else if (nQ.empty()) {
		rtn = pQ.top(); pQ.pop();
	}
	else if (-nQ.top() <= pQ.top()) {
		rtn = nQ.top(); nQ.pop();
	}
	else {
		rtn = pQ.top(); pQ.pop();
	}
	return rtn;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	FOR(i, 0, N) {
		int v;
		cin >> v;
		if (!v) cout << getValue() << '\n';
		else {
			if (0 < v) pQ.push(v);
			else nQ.push(v);
		}
	}
}