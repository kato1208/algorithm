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
    ll N;
    cin >> N;
    Heap A, B;
    rep(i, N) {
        ll a;
        cin >> a;
        A.push(a);
    }
    rep(i, N) {
        ll b;
        cin >> b;
        B.push(b);
    }

    ll res = 0;

    rep(i, N) {
        ll a = A.top();
        ll b = B.top();
        A.pop();
        B.pop();
        res += abs(a - b);
    }

    cout << res << endl;
    return 0;
}