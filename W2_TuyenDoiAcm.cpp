#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen(taskname".inp", "r")) {
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
}
void Solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &i: a) cin >> i;

	{
		vector<int> b = a;
		sort(b.begin(), b.end());
		for (auto &i: a) {
			i = lower_bound(b.begin(), b.end(), i) - b.begin() + 1;
			i = (i + k - 1) / k;
		}
	}

	vector<int> val;
	for (auto &i: a) {
		auto it = upper_bound(val.begin(), val.end(), i);
		if (it == val.end()) val.push_back(i);
		else *it = i;
	}

	cout << n - val.size();
}

int main(){
	Input();
	Solve();
	return 0;
}
