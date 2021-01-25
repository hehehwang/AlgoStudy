#include <bits/stdc++.h>
using namespace std;
// 10845 큐

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int c;
	queue<int> qqq;

	cin >> c;

	for (int i = 0; i < c; i++) {
		string s;
		int v;

		cin >> s;

		if (s == "push") {
			cin >> v;
			qqq.push(v);
		}
		else if (s == "pop") {
			if (qqq.empty()) cout << -1 << "\n";
			else {
				cout << qqq.front() << "\n";
				qqq.pop();
			}
		}
		else if (s == "size") cout << qqq.size() << "\n";
		else if (s == "empty") cout << qqq.empty() << "\n";
		else if (s == "front") {
			if (qqq.empty()) cout << -1 << "\n";
			else cout << qqq.front() << "\n";
		}
		else if (s == "back") {
			if (qqq.empty()) cout << -1 << "\n";
			else cout << qqq.back() << "\n";
		}
	}
}