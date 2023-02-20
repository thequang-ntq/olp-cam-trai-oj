#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using ll = long long;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define endl '\n'
#define rep(i,n) for(int i = 0 ; i < (n) ; ++i)
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int INF = 1e6;
void setIO(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
}
vector<ll> fac(INF + 1);
void precompute(){
    fac[0] = 1;
    for(int i = 1 ; i <= 1e6 ; ++i)
        fac[i] = (fac[i-1] * i) % MOD;
}
ll powmod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void Solve(){
    int n,k;
    cin >> n >> k;
    cout << fac[n] * powmod(fac[k], MOD - 2) % MOD * powmod(fac[n - k], MOD - 2) % MOD << endl;
}

int main(){
    setIO();
    precompute();
    int test=1;
    cin >> test;
    while(test--){
        Solve();
    }
}
