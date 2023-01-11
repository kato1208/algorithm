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
    ll N, Q;
    cin >> N;
    vector<ll> v1(N, 0), v2(N, 0);
    vector<ll> s1(N+1), s2(N+1);
    rep(i, N) {
        int c;
        cin >> c;
        if (c == 1) cin >> v1[i];
        else cin >> v2[i];
    }
    rep(i, N) {
        s1[i+1] = s1[i] + v1[i];
        s2[i+1] = s2[i] + v2[i];
    }
    cin >> Q;
    rep(i, Q) {
        ll l, r;
        cin >> l >> r;

        cout << s1[r] - s1[l-1] << ' ' << s2[r] - s2[l-1] << endl;
    }
    return 0;
}