// 10808 알파벳 개수

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	vector<int> d(26, 0);
	for (char c : s) d[int(c) - int('a')] += 1;
	for (int i : d) cout << i << ' ';
}