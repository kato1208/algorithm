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
  string S;
  cin >> S;
  int ans = 0;
  rep(i, S.size()) {
    if (S.at(i) == 'w') {
      ans += 2;
    } else {
      ans += 1;
    }
  }

  cout << ans << endl;
  return 0;
}