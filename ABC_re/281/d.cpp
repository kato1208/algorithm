#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

int main() {
  ll N, K, D;
  cin >> N >> K >> D;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a.at(i);
  }
  vector dp(N+1, vector(K+1, vector<ll>(D, -1)));
  dp[0][0][0] = 0;

  rep(i, N) {
    rep(j, K+1) {
      rep(k, D) {
        if (dp[i][j][k] == -1) continue;
        // a_iを選ばない
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

        // a_iを選ぶ
        if (j != K) {
          dp[i+1][j+1][(k+a.at(i))%D] = max(dp[i+1][j+1][(k+a.at(i))%D], dp[i][j][k] + a.at(i));
        }
      }
    }
  }

  cout << dp[N][K][0] << endl;
  return 0;
}