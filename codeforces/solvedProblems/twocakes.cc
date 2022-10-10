#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,a,b;
    cin >> n >> a >> b;
    int ta, tb;
    int ans = 0;
    for(int i = 1; i < a+b; i++){
        int can = a/i + b/i;
        if(can >= n && a >= i && b >=i){
            ans = i;
        }
    }
    cout << ans;
}

int main(){
    int t;
    // cin >> t;
    // while(t--){
        solve();
    // }
}