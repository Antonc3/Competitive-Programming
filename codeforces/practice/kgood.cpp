#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;

    ll x = n;
    if(n%2==1){
        cout << 2 << endl;
        return;
    }
    while(x%2==0){
        x/=2;
    }
    if(x == 1){
        cout << "-1\n";
        return;
    }
    cout <<min(x,2*n/x) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}