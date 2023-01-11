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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> A_inv(W, vector<ll>(H));
    rep(i, H) rep(j, W) {
        int a;
        cin >> a;
        A[i][j] = a;
        A_inv[j][i] = a;
    }

    rep(i, H) {
        ll row = accumulate(A[i].begin(), A[i].end(), 0LL);
        rep(j, W) {
            ll column = accumulate(A_inv[j].begin(), A_inv[j].end(), 0LL);
            cout << row + column - A[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}