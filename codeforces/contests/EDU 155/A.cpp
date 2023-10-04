#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> w(n), end(n);
    for(int i =0; i < n; i++){
        cin >> w[i] >> end[i];
    }
    int gw = -1;
    for(int i =1 ; i < n; i++){
        if(w[i] >= w[0]){
            gw = max(gw, end[i]);
        }
    }
    if(gw >= end[0]){
        cout << -1 << endl;
    }
    else{

        cout << w[0] << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}