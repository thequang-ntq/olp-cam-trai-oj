#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

typedef long long ll;

void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(taskname".inp", "r")) {
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
}

void Solve() {
	string a; cin >> a;
	int n = a.size();

	vector<vector<bool>> isPalin(n, vector<bool>(n, false));
	vector<vector<ll>> dp(n, vector<ll>(n, 0));

	for (int i = 0; i < n; i++) dp[i][i] = isPalin[i][i] = 1;
	for (int len = 2; len <= n; len++)
		for (int i = 0, j = len - 1; j < n; i++, j++) {
			dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
			isPalin[i][j] = (a[i] == a[j] && (i + 1 == j || isPalin[i + 1][j - 1]));
			dp[i][j] += isPalin[i][j];
		}

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << dp[l - 1][r - 1] << "\n";
	}
}
