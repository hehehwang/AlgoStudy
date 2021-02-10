#include <bits/stdc++.h>
using namespace std;
// 1931 회의실 배정
#define FOR(i, n, m) for(int i=(n); i<(m); i++)

vector<pair<int, int>> schedule;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    FOR(i, 0, N) {
        int s, e;
        cin >> s >> e;
        schedule.push_back({ e, s });
    }
    sort(schedule.begin(), schedule.end());
    int time = 0, meetings = 0;
    FOR(i, 0, N) {
        if (schedule[i].second < time) continue;
        time = schedule[i].first;
        meetings++;
    }
    cout << meetings;
}