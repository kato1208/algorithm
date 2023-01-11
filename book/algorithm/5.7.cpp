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
  string S, T;
  cin >> S >> T;
  // atcoder acodr acodr

  vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));

  rep(i, S.size()+1) rep(j, T.size()+1) {
    if (i > 0 && j > 0) {
        if (S[i-1] == T[j-1]) {
            chmax(dp[i][j], dp[i-1][j-1] + 1);
        } else {
            chmax(dp[i][j], dp[i-1][j-1]);
        }

        if (i > 0) chmax(dp[i][j], dp[i-1][j]);
        if (j > 0) chmax(dp[i][j], dp[i][j-1]);
    }
  }

  int ans = 0;

  cout << ans << endl;
  return 0;
}