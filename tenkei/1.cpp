#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
template <class T> void chmax(T &a, T b) { if (a < b) a = b; }
template <class T> void chmin(T &a, T b) { if (a > b) a = b; }
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;
const long long INF = 1LL << 60;

int main() {
    ll N, L, K;
    cin >> N >> L >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    auto check = [&](ll x) -> bool {
        ll num = 0;
        ll pre = 0;

        rep(i, N) {
            if (A[i] - pre >= x) {
                ++num;
                pre = A[i];
            }
        }

        if (L - pre >= x) ++num;
        return (num >= K + 1);
    };

    ll left = -1, right = L + 1;
    while (right - left > 1) {
        ll mid  = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}