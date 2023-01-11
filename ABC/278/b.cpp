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
  int H, M;
  cin >> H >> M;
  // 0 <= H <= 23, 0 <= M <= 59

  // Hは0~15, 20~24の範囲にいる必要あり
  // MはHが0~19の場合はどんな値でもOK, 20~24の場合は0~40分までの必要がある。
  while (true) {
    if (((0 <= H  && H <= 15) || (20 <= H && H <= 24)) && (((20 <= H && H < 24) && (0 <= M && M < 40)) || (0 <= H && H <= 19))) {
      break;
    } else {
      if (M != 59) {
        M += 1;
      } else if (H != 24) {
        M = 0;
        H += 1;
      } else {
        M = 0;
        H = 0;
      }
    }
  }

  cout << H << ' ' << M << endl;
  return 0;
}