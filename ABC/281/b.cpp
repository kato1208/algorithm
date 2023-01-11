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

  if (S.length() != 8) {
    cout << "No" << endl;
    return 0;
  }

  if ('A' <= S[0] && S[0] <= 'Z' && 'A' <= S[7] && S[7] <= 'Z') {
  } else {
    cout << "No" << endl;
    return 0;
  }

  if ('1' <= S[1] && S[1] <= '9') {

  } else {
    cout << "No" << endl;
    return 0;
  }

  for (int i = 2; i < 7; i++) {
    if ('0' <= S[i] && S[i] <= '9') {
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}