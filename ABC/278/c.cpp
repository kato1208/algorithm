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
  ll N, Q;
  cin >> N >> Q;
  ll t, a, b;
  map<P, int> m;
  string ans;
  rep(i, Q) {
    cin >> t >> a >> b;
    P p1(a, b);
    P p2(b, a);
    if (t == 1) {
      m[p1] = 1;
    } else if (t == 2) {
      m[p1] = 0;
    } else {
      if (m[p1] == 1 && m[p2] == 1) {
        ans += "Yes\n";
      } else {
        ans += "No\n";
      }
    }
  }
  ans.pop_back();
  cout << ans << endl;

  return 0;
}