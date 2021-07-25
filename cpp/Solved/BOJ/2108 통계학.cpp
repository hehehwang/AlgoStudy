#include <bits/stdc++.h>
// 2108 통계학
// https://www.acmicpc.net/problem/2108
using namespace std;

vector<int> nums(500'002, 4002), numCnt(8002, 0), modeLst;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    int mxn = -4000, mnn = 4000, sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        numCnt[num + 4000]++;
        nums[i] = num;
        if (mxn < num) mxn = num;
        if (num < mnn) mnn = num;
        sum += num;
    }
    sort(nums.begin(), nums.end());
    int mxCnt = 0;
    for (int v : numCnt)
        mxCnt = (mxCnt < v) ? v : mxCnt;
    for (int i = 0; i < 8001; i++)
        if (numCnt[i] == mxCnt) modeLst.push_back(i - 4000);
    sort(modeLst.begin(), modeLst.end());
    cout << round(sum * 1.0 / N) << '\n'
         << nums[N / 2] << '\n'
         << ((modeLst.size() == 1) ? modeLst[0] : modeLst[1]) << '\n'
         << mxn - mnn;
}