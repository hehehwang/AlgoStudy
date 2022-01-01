#include <bits/stdc++.h>
// 1450 냅색문제
// https://www.acmicpc.net/problem/1450
using namespace std;
using ll = long long;

int N, C, t, Pa, Pb, ans;
vector<int> Wa, Wb;
vector<ll> Ba, Bb;
void getBag(int P, vector<ll> &bag, vector<int> &W) {
    for (int c = 0; c < P; c++) {
        t = c;
        int idx = 0;
        ll tmp = 0;
        while (t) {
            if (t % 2)
                tmp += W[idx];
            t /= 2;
            idx += 1;
        }
        if (tmp <= C)
            bag.push_back(tmp);
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (i < N / 2)
            Wa.push_back(t);
        else
            Wb.push_back(t);
    }
    Pa = 1 << Wa.size();
    Pb = 1 << Wb.size();
    Ba.reserve(Pa);
    Bb.reserve(Pb);
    getBag(Pa, Ba, Wa);
    getBag(Pb, Bb, Wb);
    sort(Ba.begin(), Ba.end());
    sort(Bb.begin(), Bb.end());
    for (auto ait = Ba.begin(); ait < Ba.end(); ait++) {
        for (auto bit = Bb.begin(); bit < Bb.end(); bit++) {
            if (C < *ait + *bit) break;
            ans++;
        }
    }

    cout << ans;
}