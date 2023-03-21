#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < 2*n; i++){
        cin >> a[i];
        if(a[i]&1) odd.push_back(i+1);
        else even.push_back(i+1);
    }
    int totcnt = 0;
    for(int i = 0; totcnt < 2*n-2&& i < odd.size()-(odd.size()%2); i+=2){
        totcnt+=2;
        cout<<odd[i] << " " << odd[i+1]<<"\n"; 
    }
    for(int i = 0; totcnt < 2*n-2&&i < even.size()-(even.size()%2); i+=2){
        totcnt+=2;
        cout<<even[i] << " " << even[i+1]<<"\n"; 
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
