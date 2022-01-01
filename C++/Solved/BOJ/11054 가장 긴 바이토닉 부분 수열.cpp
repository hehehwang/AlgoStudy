#include <bits/stdc++.h>
// 11054 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054
using namespace std;

const int MXN = 1002;
int arr[MXN], dpF[MXN], dpR[MXN], ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i < N + 1; i++) cin >> arr[i];
    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) dpF[i] = max(dpF[j] + 1, dpF[i]);
        }
    }
    for (int i = N; 0 < i; i--) {
        for (int j = N + 1; i < j; j--)
            if (arr[j] < arr[i]) dpR[i] = max(dpR[j] + 1, dpR[i]);
    }
    for (int i = 1; i < N + 1; i++) ans = max(ans, dpF[i] + dpR[i]);
    cout << ans - 1;
}