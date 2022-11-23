#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Solve(){
    int n, k; cin >> n >> k;
    k--;
    ll a[n + 1][n + 1], F[n + 1][n + 1];
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            cin >> a[i][j];
        }
    }
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            F[i][j] = a[i][j] + F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1];
        }
    }
    ll ans = 0;
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            if(i + k <= n && j + k <= n){
                ll res = F[i + k][j + k] - F[i + k][j - 1] - F[i - 1][j + k] + F[i - 1][j - 1];
                ans = max(ans, res);
            }
        }
    }
    cout << ans;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int cas = 1; 
  //cin >> cas;
  while(cas--) Solve();
  return 0;
}
