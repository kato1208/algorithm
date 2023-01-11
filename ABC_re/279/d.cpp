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
  ll A, B;
  cin >> A >> B;

  auto f = [&](ll n) -> double {
    return (double) B * n + (double) A / sqrt(n + 1);
  };

  ll l = 0, r = A / B;

  while (r - l > 2) {
    ll m1 = (2 * l + r) / 3;
    ll m2 = (l + 2 * r) / 3;
    if (f(m1) >= f(m2)) l = m1;
    else r = m2;
  }

  double ans = A;

  for (ll i = l; i <= r; i++) {
    ans = min(ans, f(i));
  }

  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}