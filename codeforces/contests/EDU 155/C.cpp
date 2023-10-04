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
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> fact(n+2),invfact(n+2);
    fact[0] = invfact[0] = 1;
    for(int i =1 ; i < n+2; i++){
        fact[i] = (fact[i-1]*i)%M;
        invfact[i] = fastpow(fact[i],M-2);
    }
    int i = 0;
    ll ans1 = 0;
    ll ans2 = 1;
    while(i < n){
        char c = s[i];
        int x = i;
        while(x < n && s[x] == c){
            x++;
        }
        int diff = (x-i);
        ans1 += diff - 1;
        ans2 = (ans2 * diff) % M;
        i = x;
    }
    ans2 = (ans2 * fact[ans1]) % M;
    cout << ans1 << " " << ans2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}