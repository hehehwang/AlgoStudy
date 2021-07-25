#include <bits/stdc++.h>
// 이항 계수 3
// https://www.acmicpc.net/problem/11401
using namespace std;
typedef long long ll;
const int p = 1'000'000'007;

int N, K;
int singleMod(int num) {
    if (p < num) return num - p;
    return num;
}
int raise(int num, int pwr) {
    if (pwr == 1) return num;
    int tmp = raise(num, pwr / 2);
    tmp = (1ll * tmp * tmp) % p;
    if (pwr % 2) return (1ll * tmp * num) % p;
    else
        return tmp;
}
int facto(int n) {
    int rtn = 1;
    for (int i = 1; i <= n; i++)
        rtn = (1ll * rtn * i) % p;
    return rtn;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int num = facto(N);
    int denom = raise((1ll * facto(N - K) * facto(K)) % p, p - 2) % p;
    cout << (1ll * num * denom) % p;
}