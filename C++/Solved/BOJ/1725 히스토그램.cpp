#include <bits/stdc++.h>
// 1725 히스토그램
// https://www.acmicpc.net/problem/1725
using namespace std;
using PII = pair<int, int>;

long long ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> histo(N + 2), left(N + 1), right(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> histo[i];

    stack<PII> stk;
    stk.push({0, 0});
    for (int i = 1; i <= N + 1; i++) {
        while (histo[i] < stk.top().second) {
            right[stk.top().first] = i;
            stk.pop();
        }
        stk.push({i, histo[i]});
    }
    for (int i = N; i >= 0; i--) {
        while (histo[i] < stk.top().second) {
            left[stk.top().first] = i;
            stk.pop();
        }
        stk.push({i, histo[i]});
    }
    for (int i = 1; i <= N; i++)
        ans = max(ans, 1ll * histo[i] * (right[i] - left[i] - 1));
    cout << ans << '\n';
}