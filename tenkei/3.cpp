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
    ll N;
    cin >> N;

    Graph G(N);
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    auto dist0 = dfs(G, 0);

    int mx = -1, mv = -1;
    rep(v, N) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }

    auto distmv = dfs(G, mv);

    mx = 0;
    rep(v, N) {
        chmax(mx, distmv[v]);
    }

    cout << mx + 1 << endl;
    return 0;
}