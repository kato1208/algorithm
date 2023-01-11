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

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

int main() {
    ll H, W, Q, t, r, c, ra, ca, rb, cb;
    cin >> H >> W >> Q;
    UnionFind uf(H*W);
    vector<vector<ll>> color(H, vector<ll>(W, 0));
    rep(i, Q) {
        cin >> t;
        if (t == 1) {
            cin >> r >> c;
            --r, --c;
            color[r][c] = 1;
            rep(i, 4) {
                ll x = c + dx[i];
                ll y = r + dy[i];
                if (0 <= x && x <= W-1 && 0 <= y && y <= H-1 && color[y][x] == 1) {
                    uf.unite(W * r + c, W * y + x);
                }
            }
        } else {
            cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            if (color[ra][ca] == 1 && color[rb][cb] == 1 && uf.issame(W * ra + ca, W * rb + cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}