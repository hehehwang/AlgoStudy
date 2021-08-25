#include <bits/stdc++.h>
// 2470 두 용액
// https://www.acmicpc.net/problem/2470
using namespace std;

int N, liq[100002], tsum = 2'000'000'001;
pair<int, int> ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> liq[i];
    sort(liq, liq + N);

    int *st = liq, *en = liq + N - 1;
    while (st != en) {
        int tmp = *st + *en;
        if (abs(tmp) < tsum) {
            tsum = abs(tmp);
            ans = {*st, *en};
        }
        if (tmp < 0) st++;
        else if (0 < tmp)
            en--;
        else
            break;
    }
    cout << ans.first << ' ' << ans.second;
}