#include <bits/stdc++.h>
#define taskname "M"
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
	ll p, q; cin >> p >> q;

	ll ans = 1e18;
	for (ll p10 = 1; p10 <= 1e10; p10 *= 10)
		for (int a = 1; a <= 9; a++) {
			ll t = a * (p * p10 - q);
			ll m = q * 10 - p;
			
			if (t <= 0 && m < 0) t *= -1, m *= -1;
			if (t >= 0 && m > 0 && t % m == 0 && t / m < p10) 
				ans = min(ans, a * p10 + t / m);
		}
	
	if (ans == 1e18) cout << -1;
	else cout << ans;
}

int main(){
	Input();
	Solve();
	return 0;
}
