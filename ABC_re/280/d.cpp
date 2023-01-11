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

vector<pair<long long, long long> > prime_factorize(long long N) {
    // 答えを表す可変長配列
    vector<pair<long long, long long> > res;

    // √N まで試し割っていく
    for (long long p = 2; p * p <= N; ++p) {
        // N が p で割り切れないならばスキップ
        if (N % p != 0) {
            continue;
        }

        // N の素因数 p に対する指数を求める
        int e = 0;
        while (N % p == 0) {
            // 指数を 1 増やす
            ++e;

            // N を p で割る
            N /= p;
        }

        // 答えに追加
        res.emplace_back(p, e);
    }

    // 素数が最後に残ることがありうる
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}

int main() {
  ll K;
  cin >> K;
  const auto& pf = prime_factorize(K);
  ll ans = 0;
  for (auto [p, e] : pf) {
    ll f = 0;
    for (ll i = p; ; ) {
      ll cnt = 0;
      ll g = i;
      while (g % p == 0) {
        cnt += 1;
        g /= p;
      }
      f += cnt;
      if (f >= e) {
        ans = max(ans, i);
        break;
      }
      i += p;
    }
  }

  cout << ans << endl;
  return 0;
}