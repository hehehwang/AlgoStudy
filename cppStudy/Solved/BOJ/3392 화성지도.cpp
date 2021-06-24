#include <bits/stdc++.h>
// 3392 화성 지도
// https://www.acmicpc.net/problem/3392
using namespace std;

int brush[30'002];
priority_queue<tuple<int, bool, int, int>,
               vector<tuple<int, bool, int, int>>,
               greater<>>
    pQ;
void switchEdge(int a, int b, bool isMark) {
    for (int i = a; i < b; i++)
        brush[i] += (isMark ? 1 : -1);
}
int getBrushLength() {
    int cnt = 0;
    for (auto i : brush) cnt += bool(i);
    return cnt;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, x1, y1, x2, y2;
    int answer = 0, cursor = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        pQ.push({x1, true, y1, y2});
        pQ.push({x2, false, y1, y2});
    }
    while (pQ.size()) {
        int nextX, isMark, a, b;
        tie(nextX, isMark, a, b) = pQ.top();
        pQ.pop();
        if (nextX != cursor) {
            answer += (nextX - cursor) * getBrushLength();
            cursor = nextX;
        }
        switchEdge(a, b, isMark);
    }
    cout << answer;
}