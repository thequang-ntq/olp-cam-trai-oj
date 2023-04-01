#include <bits/stdc++.h>
using namespace std;

vector <vector<long long>> mulmatrix(const vector<vector<long long>>&A, const vector <vector<long long>>&B){
    int n=A.size();
    vector <vector<long long>> C(n, vector <long long>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                    C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
            }
        }
    }
    return C;
}
int sum(int a,int b){
    return a+b;
}
int main(){
    int Tc;
    cin >> Tc;
    for (int i=0;i<Tc;i++){
        int n;
        cin >> n;
        vector <vector<long long>> A(n, vector <long long>(n));
        vector <vector<long long>> B(n, vector <long long>(n));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> A[i][j];
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> B[i][j];
            }
        }
        auto A2=mulmatrix(A,A);
        auto A3=mulmatrix(A2,A);
        if (A3==B) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
