#include <bits/stdc++.h>
// 2261 가장 가까운 두 점
// https://www.acmicpc.net/problem/2261
using namespace std;
#define X first
#define Y second
typedef pair<int, int> PII;

int N;
PII C[100'002];
bool cmp(PII &A, PII &B) {
    return (A.Y < B.Y);
}
int hDist(PII &A, PII &B) {
    return (A.X - B.X) * (A.X - B.X);
}
int vDist(PII &A, PII &B) {
    return (A.Y - B.Y) * (A.Y - B.Y);
}
int dist(PII &A, PII &B) {
    return hDist(A, B) + vDist(A, B);
}
int dc(int s, int e) {
    // 범위 사이에 점이 두 개면 그 두 점의 길이를 반환한다.
    if (e - s == 2) return dist(C[s], C[s + 1]);
    // 범위 사이에 점이 세 개면 brute force
    if (e - s == 3) return min({dist(C[s], C[s + 1]),
                                dist(C[s + 1], C[s + 2]),
                                dist(C[s + 2], C[s])});
    int m = (s + e) / 2;
    int minDist = min(dc(s, m + 1), dc(m, e));
    vector<PII> mid;
    mid.reserve(e - s);
    // for (int i = 0; i < N; i++) {
    //     if (hDist(C[i], C[m]) < minDist) mid.push_back(C[i]);
    // }
    for (int i = m; i < e; i++) {
        if (minDist <= hDist(C[i], C[m])) break;
        mid.push_back(C[i]);
    }
    for (int i = m - 1; s <= i; i--) {
        if (minDist <= hDist(C[i], C[m])) break;
        mid.push_back(C[i]);
    }
    sort(mid.begin(), mid.end(), cmp);
    int T = mid.size();
    for (int i = 0; i < T - 1; i++)
        for (int j = i + 1; j < T; j++) {
            if (minDist <= vDist(mid[i], mid[j])) break;
            minDist = min(minDist, dist(mid[i], mid[j]));
        }
    return minDist;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i].X >> C[i].Y;
    };

    sort(C, C + N);
    cout << dc(0, N);
}