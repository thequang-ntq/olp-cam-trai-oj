#include <iostream>
#include <string>
using namespace std;
struct sinhvien{
    string masv;
    int diem;
    void nhaptt(){
        cin>>masv>>diem;
    }
    void intt(){
        cout<<masv<<" "<<diem<<endl;
    }
    
    
};
int main(){
    int n; cin>>n;
    sinhvien sv[100];
    int count=0;
    for (int i=0;i<n;i++){
        sv[i].nhaptt();
    }
    for (int i=0;i<n;i++){
        if (sv[i].diem >=4) count++;
    }
    cout<<count<<endl;
    for (int i=0;i<n;i++){
        if (sv[i].diem >=4) sv[i].intt();
    }
    
    return 0;
}
