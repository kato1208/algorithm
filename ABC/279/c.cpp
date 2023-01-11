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
  int H, W;
  cin >> H >> W;
  vector<string> S(H), T(H), TS(W), TT(W);
  rep(i, H) cin >> S.at(i);
  rep(i, H) cin >> T.at(i);

  rep(i, H) {
    rep(j, W) {
      TS.at(j).push_back(S.at(i).at(j));
      TT.at(j).push_back(T.at(i).at(j));
    }
  }

  sort(TS.begin(), TS.end());
  sort(TT.begin(), TT.end());

  if (TS == TT) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}