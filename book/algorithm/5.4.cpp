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
  int N, W, k;
  cin >> N >> W >> k;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  vector<vector<int>> dp(N+1, vector<int>(W+1, INF));
  dp[0][0] = 0;

  rep(i, N) rep(j, W) {
    // a_iを選ぶ
    if (j >= a[i]) dp[i+1][j] = min(dp[i+1][j], dp[i][j-a[i]]+1);

    // a_iを選ばない
    dp[i+1][j] = dp[i][j];
  }

  if (dp[N][W] <= k) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}