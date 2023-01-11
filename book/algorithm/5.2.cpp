#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> a;

  rep(i, N) {
    cin >> a[i];
  }

  vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));
  dp[0][0] = true;

  rep(i, N) {
    rep(j, W) {
        // a_iを選ぶ場合
        if (j >= a[i]) dp[i+1][j] = dp[i+1][j] || dp[i][j-a[i]];

        // a_iを選ばない場合
        dp[i+1][j] = dp[i+1][j] || dp[i][j];
    }
  }

  int ans = 0;

  cout << ans << endl;
  return 0;
}