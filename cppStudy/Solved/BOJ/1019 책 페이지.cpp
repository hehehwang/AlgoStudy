#include <bits/stdc++.h>
// 1019 책 페이지
// https://www.acmicpc.net/source/13229145
using namespace std;

vector<int> ans(10);
int mult;
int pwr() {
    int n = 1;
    for (int i = 0; i < mult; i++) n *= 10;
    return n;
}
void adr(int n) {
    while (n) {
        ans[n % 10] += pwr();
        n /= 10;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s = 1, e;
    cin >> e;

    while (18 < e) {
        while (s % 10 != 0) adr(s++);
        while (e % 10 != 9) adr(e--);
        int chunk = (e - s) / 10 + 1;
        for (auto v = ans.begin(); v < ans.end(); v++)
            *v += chunk * pwr();
        s /= 10;
        e /= 10;
        mult++;
    }
    while (s != e + 1) adr(s++);
    for (int v : ans) cout << v << ' ';
}