#include <bits/stdc++.h>
// 6549 히스토그램에서 가장 큰 직사각형 [분할정복]
// https://www.acmicpc.net/problem/6549
using namespace std;
typedef long long ll;

int hist[100002], N;
ll fromMid(int m, int s, int e) {
    int l = m, r = m, h = hist[m];
    ll rtn = h;
    while (1) {
        // 오른쪽 바의 길이가 더 길거나 왼쪽으로 이동할 수 없는 경우
        if (r != e - 1 && (l == s || hist[l - 1] < hist[r + 1])) r++;
        else
            l--;
        if (l < s || e <= r) break;
        h = min({h, hist[r], hist[l]});
        rtn = max(rtn, 1ll * h * (r - l + 1));
    }
    return rtn;
}
ll bs(int s, int e) {
    if (s == e) return 0;
    if (e - s == 1) return hist[s];
    int m = (s + e) / 2;
    ll L = bs(s, m), R = bs(m, e), C = fromMid(m, s, e);
    // cout << s << ", " << e << '\n';
    // cout << L << ' ' << C << ' ' << R << '\n';
    return max({L, R, C});
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1) {
        cin >> N;
        if (!N) break;
        for (int i = 0; i < N; i++) cin >> hist[i];
        cout << bs(0, N) << '\n';
    }
}