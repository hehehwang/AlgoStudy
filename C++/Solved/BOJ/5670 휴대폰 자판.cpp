/*
5670 휴대폰 자판
https://www.acmicpc.net/problem/5670
*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int ROOT = 1, MAX_NODE_N = 1e6 + 10;
int node_id, ans;
bool chk[MAX_NODE_N];
vector<pair<int, int>> nxt[MAX_NODE_N];

int getchild(int node, char c) {
  for (auto [id, c_] : nxt[node])
    if (c == c_) return id;
  return -1;
}
void insert(string& s) {
  int curr = ROOT;
  for (auto c : s) {
    int child = getchild(curr, c);
    if (child == -1) {
      child = node_id;
      nxt[curr].push_back({node_id++, c});
    }
    curr = child;
  }
  chk[curr] = true;
}
bool search(string& s) {
  int curr = ROOT;
  for (auto c : s) {
    int child = getchild(curr, c);
    if (child == -1) return false;
    curr = child;
  }
  return chk[curr];
}
void dfs(int curr, int key_strokes) {
  if (chk[curr])
    ans += ++key_strokes;
  else if (nxt[curr].size() > 1)
    ++key_strokes;
  for (auto [nxt_node, _] : nxt[curr])
    dfs(nxt_node, key_strokes);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);

  int N;
  while (cin >> N) {
    for (int i = 0; i < MAX_NODE_N; i++) nxt[i].clear();
    fill(chk, chk + MAX_NODE_N, 0);
    node_id = ROOT + 1;
    ans = 0;

    vector<string> words(N);
    for (int i = 0; i < N; i++) cin >> words[i];
    for (auto& s : words) insert(s);
    for (auto [id, _] : nxt[ROOT])
      dfs(id, 0);
    cout << 1.0 * ans / words.size() << '\n';
  }
}