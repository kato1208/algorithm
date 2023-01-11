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
    ll N;
    cin >> N;
    if (N % 2 != 0) return 0;
    string s;
    auto check = [&](string s) -> bool {
        queue<char> que;
        rep(i, N) {
            if (s[i] == ')') {
                if (!que.empty()) que.pop();
                else return false;
            }
            else que.push(s[i]);
        }
        if (que.empty()) return true;
        else return false;
    };
    for (int bit = (1 << N); bit > 0; --bit) {
        string s;
        for(int i = N - 1; i >= 0; --i) {
            if (bit & (1 << i)) s.push_back('(');
            else s.push_back(')');
        }
        if (check(s)) cout << s << endl;
    }
    return 0;
}
