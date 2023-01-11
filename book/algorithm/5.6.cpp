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
const int INF = 1<<29;

int main() {
  int N, We;
  cin >> N >> W;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  vector<int> m(N);
  rep(i, N) cin >> m[i];
  vector<vector<int>> dp(N+1, vector<int>(W+1, INF));
  dp[0][0] = 0;

  rep(i, N) rep(j, W+1) {
    // a_iを用いない場合
    if (dp[i][j] < INF) dp[i+1][j] = 0;
    if (j >= a[i] && dp[i+1][j-a[i]] < m[i]) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-a[i]]+1);
  }

  if (dp[N][W] < INF) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}