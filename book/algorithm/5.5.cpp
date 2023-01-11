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
  vector<vector<int>> dp(N+1, vector<int>(W+1, false));
  dp[0][0] = true;

  rep(i, N) rep(j, W+1) {
    if (dp[i][j]) dp[i+1][j] = true;
    if (j >= a[i] && dp[i+1][j-a[i]]) dp[i+1][j] = true;
  }

  if (dp[N][W]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}