#include <bits/stdc++.h>
// 10830 행렬 제곱
// https://www.acmicpc.net/problem/10830
using namespace std;
const int MOD = 1000;
typedef long long ll;
typedef vector<vector<int>> mat;

int N;
mat arr;
ll B;
mat matMult(mat A, mat B) {
    mat C(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int tmp = 0;
            for (int k = 0; k < N; k++) {
                tmp += A[i][k] * B[k][j] % MOD;
                tmp %= MOD;
            }
            C[i][j] = tmp;
        }
    return C;
}
mat matSq(ll B) {
    if (B == 1) return arr;
    mat rtn(N, vector<int>(N));
    rtn = matSq(B / 2);
    rtn = matMult(rtn, rtn);
    if (B % 2) return matMult(rtn, arr);
    return rtn;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        arr.push_back(vector<int>(N));
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            arr[i][j] %= MOD;
        }
    }
    mat ans = matSq(B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
}