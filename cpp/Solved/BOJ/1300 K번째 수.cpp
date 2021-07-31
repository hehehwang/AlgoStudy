#include <bits/stdc++.h>
// K번째 수
// https://www.acmicpc.net/problem/1300
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, ans;
    cin >> N >> K;
    int start = 0, end = K + 1;
    while (start < end) {
        int mid = (start + end) / 2;
        long long cnt = 0;
        for (int i = 1; i <= N; i++) cnt += min(mid / i, N);
        if (cnt < K) {
            start = mid + 1;
        } else {
            ans = mid;
            end = mid;
        }
    }
    cout << ans;
}