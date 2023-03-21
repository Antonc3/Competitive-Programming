#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100006
const ll M = 998244353;
ll fact[MAXN];
ll invfact[MAXN];
ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res*=b;
        res%=M;
        b*=b;
        b%=M;
        e/=2;
    }
    return res;
}


void solve(){
    int l,r;
    cin >> l >> r;
    int cnt = 0;
    int ll = l;
    while(ll <= r){
        cnt++;
        ll*=2;
    }
    vector<int> a;
    int ans = 0;
    ans = r/(1<<(cnt-1))-l+1;
    if(cnt>1) ans+=(cnt-1)*max(0,(r/((1<<(cnt-2))*3)-l+1));
    
    cout << cnt << " " << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
