#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n,k,x;
    cin >> n >> k >> x;
    ll rem = k;
    ll minRem = (rem*(rem+1)/2);
    ll xx = x;
    ll curMax = n;
    ll maxAmount = n*(n+1)/2 - (n-k)*(n-k+1)/2;
    if(maxAmount >= x && x >= minRem){
        cout <<"YES\n";
    }
    else{
        cout <<"NO\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}