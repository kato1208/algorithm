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
  ll n, q, num, ii, x, base=0;
  cin >> n;
  map<int, ll> a;
  rep(i, n) cin >> a[i];
  cin >> q;
  rep(i, q) {
    cin >> num;
    if (num == 3) {
      cin >> ii;
      cout << base + a[ii-1] << endl;
    } else if (num == 2) {
      cin >> ii >> x;
      a[ii-1] += x;
    } else {
      cin >> base;
      a.clear();
    }
  }
  return 0;
}