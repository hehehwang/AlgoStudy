#include <bits/stdc++.h>
// 13144 List of Unique Numbers
// https://www.acmicpc.net/problem/13144
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<bool> chk(100'002);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int st = 0, en = 1;
    long long ans = 0;
    chk[arr[st]] = 1;
    while (en != N) {
        while (chk[arr[en]] && st != en) {
            ans += (en - st);
            chk[arr[st++]] = false;
        }
        chk[arr[en++]] = true;
    }
    while (st != N)
        ans += (en - st++);

    cout << ans;
}