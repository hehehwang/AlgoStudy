#include <bits/stdc++.h>
// 2941 크로아티아 알파벳
// https://www.acmicpc.net/problem/2941
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string croatian;
    cin >> croatian;
    vector<string> toChange = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    ans += int(croatian.size());
    for (auto c : toChange) {
        string::size_type n = croatian.find(c);
        while (n != string::npos) {
            ans--;
            n = croatian.find(c, n + 1);
        }
    }
    string::size_type n = croatian.find("dz=");
    while (n != string::npos) {
        ans--;
        n = croatian.find("dz=", n + 1);
    }
    cout << ans;
}