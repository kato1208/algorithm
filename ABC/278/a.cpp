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
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);
  rep(i, K) {
    A.erase(A.begin());
    A.push_back(0);
  }
  rep(i, N) cout << A[i] << ' ';
  cout << endl;

  return 0;
}