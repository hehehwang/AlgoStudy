#include <bits/stdc++.h>
// 15922 아우으 우아으이야!!
// https://www.acmicpc.net/problem/15922
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using namespace std;
using ll = long long;

pair<ll, ll> lines[100'002], tmp;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll s, e, drawing = 0;
    cin >> N;
    FOR(i, 0, N){
        cin >> s >> e;
        lines[i] = {s, e};
    }
    sort(lines, lines + N);
    tmp = {-1'000'000'001, -1'000'000'001};
    FOR(i, 0, N) {
        tie(s, e) = lines[i];
        if (tmp.second < s){
            drawing += tmp.second - tmp.first;
            tmp.first = s;
        }
        tmp.second = max(tmp.second, e);
    }
    drawing += tmp.second - tmp.first;
    cout << drawing;
}