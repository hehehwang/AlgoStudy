#include <bits/stdc++.h>
// 10816 숫자 카드 2 [Binary search]
// https://www.acmicpc.net/problem/10816
using namespace std;

vector<int> nums(500'002, 10'000'001);
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tc, t;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums.begin(), nums.begin() + N);
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> t;
        cout << upper_bound(nums.begin(), nums.begin() + N, t) - lower_bound(nums.begin(), nums.begin() + N, t) << ' ';
    }
}