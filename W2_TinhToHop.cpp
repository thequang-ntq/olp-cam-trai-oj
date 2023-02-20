#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> ans1, ans2;
void Combination(ll p, ll q) {
  if (p <= q) {
    for (int i = p + 1; i <= q; i++) {
      ans2.push_back(i);
      ans1.push_back(1);
    }
  }
  else {
    for (int i = q + 1; i <= p; i++) {
      ans1.push_back(i);
      ans2.push_back(1);
    }
  }
}

void Solve () {
  ll p, q, r, s;
  while (cin >> p >> q >> r >> s) {
    // cin >> p >> q >> r >> s;
    Combination(p, q);
    Combination(s, r);
    Combination(r - s, p - q);
    int sz = (int)ans1.size();
    long double ans = 1.0;
    sort(ans1.rbegin(), ans1.rend());
    sort(ans2.rbegin(), ans2.rend());
    for (int i = 0; i < sz; i++) {
      ans *= (double(ans1[i]) / (double(ans2[i])));
    }
    cout << fixed << setprecision(5) << ans << '\n';
    ans1.clear();
    ans2.clear();
  }
}

int main () {
  ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int cas = 1;
  // cin >> cas;
  while (cas--) Solve ();
  return 0;
}
