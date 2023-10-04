#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 1e9+7;
ll fastpow(ll b, ll e){
    ll res = 1;
    while( e > 0 ){
        if(e&1) res = (res*b) % M;
        b = (b*b)%M;
        e = e/2;
    }
    return res;
}
ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

void solve(){
    vector<ll> a(3);
    vector<ll> b(3);
    for(ll &x : a) cin >> x;
    for(ll &x : b) cin >> x;
    ll gcdab = gcd(a[1],b[1]);
    if(b[1]%a[1] != 0 || a[1] > b[1] || gcdab == 1 && a[1] != 1){
        cout << 0 << endl;
        return;
    }
    if(b[0] < a[0] || a[0]+a[1]*(a[2]-1) < b[0]+b[1]*(b[2]-1)){
        cout << 0 << endl;
        return;
    }
    if((b[0]-a[0])%a[1] != 0){
        cout << 0 << endl;
        return;
    }
    if(b[0]+b[1]*(b[2]) > a[0]+a[1]*(a[2]-1) || b[0]-b[1] < a[0]){
        cout << -1 << endl;
        return;
    }
    ll am = a[1];
    map<int,int> m;
    for(ll i = 2; i*i <= am; i++){
        while(am%i == 0){
            m[i]++;
            am/=i;
        }
    }
    if(am != 1) m[am]++;
    ll total = 1;
    for(auto i = m.begin(); i != m.end(); i++){
        total = total*(i->second+1);
    }
    ll ans = 0;
    for(int i = 0; i < total; i++){
        int mask = i;
        ll curNum = b[1]/gcdab;
        for(auto j = m.begin(); j != m.end(); j++){
            int cur = mask%(j->second+1);
            curNum = curNum * fastpow(j->first,cur);
            mask/=(j->second+1);
        }
        if(lcm(a[1],curNum) != b[1]) continue;
        ans += fastpow(b[1]/curNum,2);
        ans%=M;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}