#include <bits/stdc++.h>
// 7568 덩치
// https://www.acmicpc.net/problem/7568
using namespace std;

vector<pair<int, int>> bulk;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        bulk.push_back({a, b});
    }
    for (auto me : bulk) {
        int rank = 1;
        for (auto you : bulk)
            if ((me.first < you.first) && (me.second < you.second))
                rank++;
        cout << rank << ' ';
    }
}