#include <bits/stdc++.h>
// 11000 강의실 배정
// https://www.acmicpc.net/problem/11000
#define FOR(i, n, m) for (int i = (n); i < (m); i++)
using namespace std;

int N;
pair<int, int> lecture[200'002];
priority_queue<int, vector<int>, greater<>> pQ;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        lecture[i] = {a, b};
    }
    pQ.push(0);
    sort(lecture, lecture + N);
    FOR(i, 0, N) {
        int s, e, c = pQ.top();
        tie(s, e) = lecture[i];
        pQ.pop();
        if (s < c) pQ.push(c);
        pQ.push(e);
    }
    cout << pQ.size();
}