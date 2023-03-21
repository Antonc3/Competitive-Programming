#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    vector<ll> pref(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = pref[max(i,0)]+a[i];
    }
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        ll csum = pref[r]-pref[l-1];
        ll diff = k*(r-l+1)-csum;
        if((diff+pref[n])&1) cout << "YES\n";
        else cout <<"NO\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
