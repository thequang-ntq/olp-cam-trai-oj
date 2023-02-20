#include <bits/stdc++.h>
#define taskname "N"
using namespace std;

typedef long long ll;

void Input(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if(fopen(taskname".inp", "r")){
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
}

void Solve(){
	ll x, N, M; cin >> x >> N >> M;

	auto power = [](ll b, ll e, ll m){
		ll ans = 1;
		for (; e > 0; e >>= 1, b = (b * b) % m)
			if (e & 1) ans = (ans * b) % m;
		return ans;
	};

	function<ll(ll)> f = [&](ll n){
		if (n < 0) return 0ll;

		ll k = __lg(n + 1) - 1;
		ll remain = n - (1ll << (k + 1)) + 1;

		ll ans = 1;
		for (ll i = 0; i <= k; i++) 
			ans = ans * (1 + power(x, 1ll << i, M)) % M;

		return (ans + power(x, 1ll << (k + 1), M) * f(remain - 1) % M) % M;
	};

	cout << f(N) << "\n";

	// ll ans = 0, px = 1;
	// for (int i = 0; i <= N; i++, px = (px * x) % M)
	// 	ans = (ans + px) % M;
	
	// cout << ans << "\n";
}

int main(){
	Input();
	Solve();
	return 0;
}
