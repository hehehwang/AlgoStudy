#include <bits/stdc++.h>
using namespace std;
// 1644 소수의 연속합
const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i * i < MXN; i++) {
        if (!seive[i]) continue;
        for (int j = i * i; j < MXN; j += i)
            seive[j] = false;
    }
    for (int i = 2; i < MXN; i++)
        if (seive[i]) primes.push_back(i);
    primes.push_back(0);

    int target, ans = 0, tmpSum = primes[0];
    auto s = primes.begin(), e = s + 1;
    cin >> target;
    while (1) {
        if (tmpSum == target) ans++;
        if (tmpSum <= target) tmpSum += *(e++);
        else if (target < tmpSum)
            tmpSum -= *(s++);
        if (e == primes.end() || target < *s) break;
    }
    cout << ans;
}