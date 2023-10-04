#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll ma = 1e9, mb = 1e9, sa = 0, sb = 0;
    for(ll &x : a){
        cin >> x;
        ma = min(ma, x);
        sa += x;
    }
    for(ll &x : b){
        cin >> x;
        mb = min(mb, x);
        sb += x;
    }
    ll ans = 1ll*ma*n + sb;
    ans = min(ans, 1ll*mb*n+sa);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}