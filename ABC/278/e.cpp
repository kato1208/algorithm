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

int main() {
  int H, W, N, h, w, K, L;
  cin >> H >> W >> N >> h >> w;
  K = H - h;  // 3-2=1
  L = W - w;  // 4-2=2
  vector<vector<int>> A(H, vector<int>(W));
  map<int, int> m;
  set<int> s;
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      m[A[i][j]] += 1;
      s.insert(A[i][j]);
    }
  }

  rep(k, K+1) {
    rep(l, L+1) {
      map<int, int> m2(m);
      // cout << k << ' ' << l << endl;
      int cnt = 0;
      for(int i = k; i < k+h; ++i) {
        for(int j = l; j < l+w; ++j) {
          m2[A[i][j]] -= 1;
          if (m2[A[i][j]] == 0 ) cnt += 1;
        }
      }
      // for (auto iter = m2.begin(); iter != m2.end(); ++iter) {
      //   if (iter->second > 0) cnt += 1;
      // }
      cout << s.size() - cnt << ' ';
    }
    cout << endl;
  }

  return 0;
}