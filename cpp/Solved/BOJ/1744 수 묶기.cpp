#include <bits/stdc++.h>
// 1744 수 묶기
// https://www.acmicpc.net/problem/1744
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
using namespace std;

long long ans;
void seqSum(vector<int> v){
    while (1 < v.size()){
        ans += *(v.end()-1) * *(v.end()-2);
        v.pop_back();
        v.pop_back();
    }
    if (v.size())
        ans += v[0];
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> seqP, seqN;
    int N, t;
    cin >> N;
    FOR(i, 0, N){
        cin >> t;
        if (t == 1) ans++;
        else if (0 < t)
            seqP.push_back(t);
        else
            seqN.push_back(t);
    }
    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<>());
    // for (auto s : seqP) cout << s << ' ';
    // cout << '\n';
    // for (auto s : seqN) cout << s << ' ';
    // cout << '\n';
    seqSum(seqP);
    seqSum(seqN);
    cout << ans;
}