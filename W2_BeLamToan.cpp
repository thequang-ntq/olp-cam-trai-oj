#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

typedef long long ll;
int nTest = 1;

void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	if (fopen("prob_419_tc_1.in.txt", "r")) {
		freopen("prob_419_tc_1.in.txt", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
	cin >> nTest;
	cin.ignore(256, '\n');
}

void Solve() {
	string s; getline(cin, s);
	vector<int> A, B, C;
	
	auto getNumber = [&](int k){
		vector<int> ans;
		for (int i = 1; i <= 9; i++)
			for (int j = 0; j <= 9; j++) {
				if (s[5 * k] != '?' && i != s[5 * k] - '0') continue;
				if (s[5 * k + 1] != '?' && j != s[5 * k + 1] - '0') continue;
				ans.push_back(i * 10 + j);
			}
		sort(ans.begin(), ans.end());
		return ans;
	};

	A = getNumber(0);
	B = getNumber(1);
	C = getNumber(2);

	auto check = [&](int a, int b, char op){
		int c = -1;
		if (op == '+') c = a + b;
		else if (op == '-') c = a - b;
		else if (op == '*') c = a * b;
		else if (a % b == 0) c = a / b;

		auto it = lower_bound(C.begin(), C.end(), c);
		if (it != C.end() && (*it) == c) return c;

		return -1;
	};

	vector<char> ops = {'+', '-', '*', '/'};
	for (auto &op: ops) {
		if (s[3] != '?' && op != s[3]) continue;
		for (auto &a: A)
			for (auto &b: B) {
				int c = check(a, b, op);
				if (c == -1) continue;
				cout << a << " " << op << " " << b << " = " << c << "\n";
				return ;
			}
	} 

	cout << "Leu leu, de bai co giao sai roi!\n";
}

int main(){
	Input();
	while (nTest--) Solve();
	return 0;
}
