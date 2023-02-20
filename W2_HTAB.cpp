#include <bits/stdc++.h>
#define taskname "J"
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
}

void Solve() {
    int n, m, k; cin >> n >> m >> k;
    vvi A(n + 2, vi(m + 2)), B(n + 2, vi(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> A[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> B[i][j];

    auto get = [&](const vvi &A, const vvi &B, int Ax, int Ay, int Bx, int By) {
        int ans = 0;
        vi h(m + 2, 0), lt(m + 2, 0), rt(m + 2, 0); 
        for (int iA = Ax, iB = Bx; iA <= n && iB <= n; iA++, iB++) {
            for (int jA = Ay, jB = By; jA <= m && By <= m; jA++, jB++)
                if (abs(A[iA][jA] - B[iB][jB]) <= k) h[jA]++;
                else h[jA] = 0;

            {
                stack<int> Q;
                for (int jA = Ay, jB = By; jA <= m && By <= m; jA++, jB++) {
                    while (Q.size() && h[Q.top()] >= h[jA]) Q.pop();
                    lt[jA] = (Q.empty() ? Ay - 1 : Q.top());
                    Q.push(jA);
                }
            }
            {
                stack<int> Q;
                for (int jA = m, jB = m; jA >= Ay && jB >= By; jA--, jB--) {
                    while (Q.size() && h[Q.top()] >= h[jA]) Q.pop();
                    rt[jA] = (Q.empty() ? m + 1 : Q.top());
                    Q.push(jA);
                }
            }

            for (int jA = Ay, jB = By; jA <= m && By <= m; jA++, jB++)
                ans = max(ans, (rt[jA] - lt[jA] - 1) * h[jA]);
        }
        return ans;
    };

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            res = max(res, get(A, B, i, j, 1, 1));
            res = max(res, get(B, A, i, j, 1, 1));
            res = max(res, get(A, B, 1, i, j, 1));
            res = max(res, get(A, B, 1, j, i, 1));
            res = max(res, get(B, A, 1, i, j, 1));
            res = max(res, get(B, A, 1, j, i, 1));
        }

    cout << res;
}

int main(){
    Input();
    Solve();
    return 0;
}
