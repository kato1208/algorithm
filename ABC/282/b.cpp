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
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  rep(i, N) {
    cin >> S[i];
  }
  int ans = 0;
  for (int i = 0; i < N -1; ++i) {
    for(int j = i + 1; j < N; ++j) {
      vector<int> r(M, 0);
      rep(k, M) {
        if (S[i][k] == 'o' || S[j][k] == 'o') {
          r[k] = 1;
        }
        if (accumulate(r.begin(), r.end(), 0) == M) {
          ans += 1;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}