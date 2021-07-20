#include <bits/stdc++.h>
// 1436 영화감독 숌
// https://www.acmicpc.net/problem/1436
using namespace std;

bool is666(int num) {
    int cnt = 0;
    while (num) {
        if (num % 10 == 6) {
            if (++cnt == 3) return true;
        } else
            cnt = 0;
        num /= 10;
    }
    return false;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, idx = 0, num = 665;
    cin >> n;
    while (n != idx)
        if (is666(++num)) idx++;

    cout << num;
}