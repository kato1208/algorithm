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
  int N;
  string S;
  cin >> N >> S;
  int flag = 0;
  rep(i, N) {
    if (S[i] == '"') {
      if (flag == 0) {
        flag = 1;
      } else {
        flag = 0;
      }
    } else if (S[i] == ',') {
      if (flag == 0) {
        S[i] = '.';
      }
    }
  }

  cout << S << endl;
  return 0;
}