#include <bits/stdc++.h>
// 10816 숫자 카드 2 [map]
// https://www.acmicpc.net/problem/10816
using namespace std;

map<int, int> nums;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tc, t;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (nums.find(t) == nums.end()) nums[t] = 1;
        else
            nums[t]++;
    }
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> t;
        cout << ((nums.find(t) == nums.end()) ? 0 : nums[t]) << ' ';
    }
}