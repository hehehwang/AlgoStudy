#include <bits/stdc++.h>
using namespace std;
// 14711 타일 뒤집기(Easy)
#define FOR(i, n, m) for(int i=(n); i<(m); i++)
constexpr int MAX = 1000;

string board[MAX+2];
int vis[MAX+2][MAX+2];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;
    board[0] = s;
    FOR(i, 0, N){
        FOR(j, 0, N) {
            if (board[i][j] == '#') {
                if (0 < j) vis[i][j - 1] ^= 1;
                if (j <= N) vis[i][j + 1] ^= 1;
                if (i <= N) vis[i + 1][j] ^= 1;
            }
        }
        FOR(j, 0, N) {
            if (vis[i][j]) board[i + 1] += '#';
            else board[i + 1] += '.';
        }
        FOR(j, 0, N) cout << board[i][j];
        cout << "\n";
    }
}
