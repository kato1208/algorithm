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
const int MOD = 1000000007;

vector<int> dfs(const Graph &G, int s) {
    int N = G.size();

    vector<int> dist(N, -1);
    dist[s] = 0;

    stack<int> st({s});
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto nv: G[v]) {
            if (dist[nv] == -1) {
                st.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }

    return dist;
}

int main() {
    ll N;
    string S, T = "atcoder";
    cin >> N >> S;
    vector<vector<ll>> dp(N+1, vector<ll>(T.size()+1, 0));
    dp[0][0] = 1;
    auto add = [](ll &a, ll b) {
        a += b;
        if (a > MOD) a -= MOD;
    };
    rep(i, N) {
        rep(j, T.size()+1) {
            // i番目を選ばない
            add(dp[i+1][j], dp[i][j]);

            // 選ぶ
            if (j < T.size() && S[i] == T[j]) add(dp[i+1][j+1], dp[i][j]);
        }
    }

    cout << dp[N][T.size()] << endl;
    return 0;
}