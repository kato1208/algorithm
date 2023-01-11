#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

template<typename T>
std::vector<T> findDiff(std::vector<T> x, std::vector<T> y) {        // no-ref、no-const
    std::vector<T> diff;
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::set_difference(x.begin(), x.end(), y.begin(), y.end(), std::back_inserter(diff));
    return diff;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    graph[u-1].push_back(v-1);
    graph[v-1].push_back(u-1);
  }

  set<P> cand;
  vector<int> v(N);
  iota(v.begin(), v.end(), 0);
  rep(i, N) {
    vector<int> diff = findDiff(v, graph[i]);
    for (int &j: diff) {
      // cout << i << ' ' << j << endl;
      cand.insert({i, j});
    }
  }

  int ans = 0;
  for(auto &c: cand) {
    vector<vector<int>> graph_orig(graph);
    graph_orig[c.first].push_back(c.second);
    int ok = 1;
    vector<int> color(N, -1);
    rep(v, N) {
      if(color[v] != -1) {continue;}
      queue<int> que; // 探索候補の頂点番号を入れるキュー
      color[v] = 0;
      que.push(v);
      // キューに要素が残っている限り
      while(que.size() > 0) {
        int qv = que.front();
        que.pop();
        // 頂点 qv に隣接している頂点 nv について、
        for(auto nv : graph_orig[qv]) {
            // nv がすでに探索済みならば、スキップする
            if(color[nv] != -1) {
                // 隣り合う頂点どうしが同じ色なら、答えは No
                if(color[nv] == color[qv]) {ok = -1;}
                continue;
            }
            // そうでなければ、頂点 nv の色を color[qv] と逆にしたうえで、nv も探索候補に入れる
            color[nv] = 1 - color[qv];
            que.push(nv);
        }
      }
    }
    if (ok == 1) {
        ans += 1;
    }
  }

  cout << ans/2 << endl;
  return 0;
}