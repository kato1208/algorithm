#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n + 1); i++)
template <class T> void chmax(T &a, T b){ if (a < b) a = b;}
template <class T> void chmin(T &a, T b){ if (a > b) a = b;}
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;
const long long INF = 1LL<<60;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a;
    rep(i, N) cin >> a[i];

    vector<vector<double>> f(N + 1, vector<double>(N + 1));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            double sum = 0;
            for (int k = j; k < i; ++k) sum += a[k];
            f[j][i] = sum / (i - j);
        }
    }

    vector<vector<double>> dp(N+1, vector<double>(M+1, -INF));
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k <= M; ++k) {
                chmax(dp[i][k], dp[j][k-1] + f[j][i]);
            }
        }
    }

    double res = -INF;
    for (int m = 0; m <= M; ++m) chmax(res, dp[N][m]);
    cout << fixed << setprecision(10) << res << endl;

    return 0;
}