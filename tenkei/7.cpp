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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    cin >> Q;
    rep(i, Q) {
        ll b;
        cin >> b;
        auto lower_iter = lower_bound(A.begin(), A.end(), b);
        if (lower_iter != A.begin()) cout << min(abs(*lower_iter-b), abs(*(lower_iter-1)-b)) << endl;
        else cout << abs(*lower_iter-b) << endl;
    }
    return 0;
}