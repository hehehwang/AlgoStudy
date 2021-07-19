#include <bits/stdc++.h>
// 2941 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string croatian;
    vector<string> toChange = {"c=", "c-", "d-", "lj", "nj", "s="};
    cin >> croatian;
    for (auto c : toChange) {
        string::size_type n = croatian.find(c);
        while (n != string::npos) {
            ans--;
            n = croatian.find(c, n + 1);
        }
    }
    int c3 = 0, c2 = 0;
    string::size_type n = croatian.find("dz=");
    while (n != string::npos) {
        c3++;
        n = croatian.find("dz=", n + 1);
    }
    n = croatian.find("z=");
    while (n != string::npos) {
        c2++;
        n = croatian.find("z=", n + 1);
    }
    ans -= 2 * (c3);
    ans -= (c2 - c3);
    ans += int(croatian.size());
    cout << ans;
}