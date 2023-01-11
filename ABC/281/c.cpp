#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using mint = modint1000000007;

int main() {
    ll N,T;
    cin>>N>>T;
    vector<ll> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ll S=0;
    for(int i=0;i<N;i++){
        S+=A[i];
    }
    T%=S;
    ll t=0;
    for(int i=0;i<N;i++){
        if(t+A[i]>T){
            cout<<i+1<<' ';
            cout<<T-t<<endl;
            return 0;
        }
        t+=A[i];
    }
    return 0;
}