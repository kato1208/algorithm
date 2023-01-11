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
const int INF = (int)1e9;
const ll INFL = (ll)1e18;
const double PI = acos(-1);
const ll MAX = (ll)1e6;

ll dfs(const Graph &G, int s) {
    ll ans = 0;
    int N = G.size();

    vector<bool> seen(N, false);

    stack<int> st({s});
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        seen[v] = true;
        for (auto nv: G[v]) {
            if (seen[nv] == false) {
                st.push(nv);
                ans++;
                if (ans > MAX) return MAX;
            }
        }
        seen[v] = false;
    }

    return ans;
}

struct UnionFind {
    vector<ll> par, siz;

    UnionFind(ll n) : par(n, -1), siz(n, 1) {}

    ll root(ll x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    bool unite(ll x, ll y) {
        x = root(x); y = root(y);

        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

struct Heap {
    vector<ll> heap;
    Heap() {}

    void push(ll x) {
        heap.push_back(x);
        ll i = (ll)heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    ll top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    void pop() {
        if (heap.empty()) return;
        ll x = heap.back();
        heap.pop_back();
        ll i = 0;
        while (i * 2 + 1 < (int)heap.size()) {
            ll child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] > heap[child1]) child1 = child2;
            if (heap[child1] <= x) break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }
};

const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

int main() {
    ll N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << dfs(G, 0) << endl;
    return 0;
}