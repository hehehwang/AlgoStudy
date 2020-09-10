// 2480 주사위 세개
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v[3];
	cin >> v[0] >> v[1] >> v[2];
	if (v[0] == v[1] && v[1] == v[2])
		cout << (10000 + v[0] * 1000);
	else if ( (v[0] == v[1]) || (v[0] == v[2]))
		cout << 1000 + 100 * v[0];
	else if (v[1] == v[2])
		cout << 1000 + 100 * v[1];
	else
		cout<< max(max(v[0], v[1]), v[2])*100;
}