#include <bits/stdc++.h>
using namespace std;
// 바킹독 그는 신인가?

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> line;

	string str;
	cin >> str;
	for (auto s : str) line.push_back(s);

	auto curr = line.end();

	int t;
	cin >> t;
	for (int i=0; i < t; i++) {
		char c;
		cin >> c;
		if (c == 'L') if (curr != line.begin()) curr--;
		if (c == 'D') if(curr != line.end()) curr++;
		if (c == 'B') {
			if (curr != line.begin()) {
				curr--;
				curr = line.erase(curr);
			}
		}
		if (c=='P') {
			char c;
			cin >> c;
			line.insert(curr, c);
		}
	}
	for (auto c : line) cout << c ;
}