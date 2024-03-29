#pragma GCC optimize("03,unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC targer("sse,sse2,sse3,ssse3,sse4,avx,abm,mmx,abx,tune=native")
#pragma GCC optimization("-funroll-all-loops, no-stack-protector")
#include <bits/stdc++.h>
#define MO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX(a,b) ((a > b ) ? a : b)
#define MIN(a,b) ( (a < b) ? a : b)
#define ABS(x) (x < 0 ? -x : x)
#define ll long long
#define MOD 1000000007
#define mod 998244353
#define div6 166666668
#define BIT(x,i) (1&((x)>>(i)))
#define MASK(x)  (1LL<<(x))
#define CNT(x) __builtin_popcountll(x)
#define taskname "__Quang__"
#define double long double
using namespace std;
using ull = unsigned long long;
const ll inf = 1000000003;
const int maxn = 1e6 + 19;
const double Pi = 3.1415926535897323846;
const double eps = 1e-9;
int sign(double x){
    if(x > eps) return 1;
    if( x < -eps) return -1;
    return 0;
}
ll __lcm(ll a, ll b){
    return (a / __gcd(a,b) * b);
}
bool pr(ll n){
    if (n <= 1) return false;
    if(n <= 3) return true;
    for(ll i=2; i*i <= n; i++){
        if( (n % i) == 0) return false;
    }
    return true;
}
bool cp(ll n){
	ll temp = sqrt(n);
	return temp * temp == n;
}
ll binpow(ll a, ll b){
    ll res =1 ;
    a %= MOD;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
// ull npk(ll n, ll k){
// 	return fac(n) / fac(n-k);
// }
// ull nck(ll k, ll n){
// 	if(k==0 || k==n ) return 1;
// 	if(k==1) return n;
// 	return nck(k-1, n-1) + nck(k, n-1);
// }
//class SegTree{
//public:
//    int n;
//    vector<ll>a,lazy,st;
//public:
//    SegTree(){}
//    SegTree(const vector<ll>&x){
//        this -> n = x.size() - 1;
//        this -> lazy.resize(n*4+5, 1e9);
//        this -> st.resize(n*4+5, 1e9);
//        this -> a = x;
//        build(1,1,n);
//    }
//    void build(int id, int l, int r){
//        if(l == r){
//            st[id] = 1e9;
//            return;
//        }
//        int mid = (l+r)>>1;
//        build(id*2, l , mid);
//        build(id * 2 + 1, mid + 1, r);
//        st[id] = 1e9;
//    }
//    void fix(int id, int l, int r){
//        if(!lazy[id]) return;
//        st[id] += lazy[id];
//        if(l != r){
//            lazy[id*2] += lazy[id];
//            lazy[id*2+1] += lazy[id];
//        }
//        lazy[id] = 0;
//    }
//    void update(int id, int l, int r, int i, int val){
////        fix(id, l , r);
//        if( i > r || i < l) return;
//        if(l == r ){
////            lazy[id] += val;
////            fix(id, l , r);
//             st[id] = val;
//            return;
//        }
//        int mid = (l+r)>>1;
//        if(i <= mid) update(id*2 , l, mid, i, val);
//        else update(id*2+1, mid + 1, r , i, val);
//        st[id] = min(st[id*2] , st[id*2+1]);
//    }
//    ll get(int id, int l, int r, int u, int v){
////        fix(id, l , r);
//        if(u > r || v < l) return inf; // tim min return 1e9
//        								//tim max return -1e9
//        								//tim tong return 0
//        if( u <= l && v >= r){
//            return st[id];
//        }
//        int mid = (l+r)>>1;
//        ll get1 = get(id*2, l, mid, u, v);
//        ll get2 = get(id*2+1, mid+1, r, u, v);
//        return min(get1 , get2); 
//    }
//};
const int N = 1010;
ll ans[N];
void precompute(){
	ans[1] = 2;
	for(int i=2; i<N; i++){
		(ans[i] = 4 * (2 * i - 1) * (ans[i-1]) ) %= MOD; 
	}
}
int main(){
    MO;
    if(fopen( taskname".inp","r")){
		freopen( taskname".inp","r", stdin);
		freopen( taskname".out","w", stdout);
	}
	int Quang = 1;
//	scanf("%d",&Quang);
	cin>>Quang;
	precompute();
	while(Quang--){
		ll n; cin>>n;
		cout<< ans[n] << '\n';
	}
    return 0;
}
