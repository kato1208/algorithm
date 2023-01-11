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
  int N;
  cin >> N;

  int s;
  int s2;
  cin >> s;
  cout << s << ' ';
  rep1(i, N-1) {
    cin >> s2;
    cout << s2-s << ' ';
    s = s2;
  }

  cout << endl;
}