#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll M = 998244353;

ll fastpow(ll a, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = res*a%M;
        a = a*a%M;
        e/=2;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    ll ans = 0;
    ll mult = 1;
    vector<int> prefix(n+1);
    prefix[0] = a[0];
    vector<int> logcnt(40,0);
    for(int i =1 ; i < n; i++){
        prefix[i] = prefix[i-1]^a[i];
    }
}

int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}