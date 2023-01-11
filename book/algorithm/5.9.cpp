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
const long long INF = 1LL<<60;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) cin >> a[i];

  vector<ll> S(N+1, 0);
  rep(i, N) S[i+1] = S[i] + a[i];

  vector<vector<ll>> dp(N+1, vector<ll>(N+1, INF));

  rep(i, N) dp[i][i+1] = 0;

  for (int bet = 2; bet <= N; ++bet) {
    for (int i = 0; i + bet <= N; ++i) {
        int j = i + bet;

        for (int k = i + 1; k < j; ++k) {
            chmin(dp[i][j], dp[i][k] + dp[k][j] + S[j] - S[i]);
        }
    }
  }

  int ans = 0;

  cout << ans << endl;
  return 0;
}