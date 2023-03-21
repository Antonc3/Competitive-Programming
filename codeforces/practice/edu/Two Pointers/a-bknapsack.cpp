#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
const bool DEBUG = false;

int main(){
    int n,m;
    ll s;
    int A,B;
    cin >> n>>m >> s>>A>>B;
    vector<ll> a(n);
    vector<ll> b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(),a.end(), [&](ll aa, ll bb){return aa > bb;});
    sort(b.begin(),b.end(), [&](ll aa, ll bb){return aa > bb;});
    vector<ll> apref(n+1,0);
    vector<ll> bpref(m+1,0);
    for(int i = 1; i <= n; i++){
        apref[i] = apref[i-1]+a[i-1];
        if(DEBUG) cout << apref[i] << " ";
    }
    if(DEBUG) cout << endl;
    for(int i = 1; i <= m; i++){
        bpref[i] = bpref[i-1]+b[i-1];
        if(DEBUG) cout << bpref[i]<<" ";
    }
    if(DEBUG) cout << endl;
    ll best = 0;
    for(int i = 0; i <= n; i++){
        ll used = 1ll*(i)*A;
        if(used > s) break;
        ll atotal = apref[i];
        ll btotal = bpref[min(1ll*m,(s-used)/B)];
        if(DEBUG) cout << "i: " << i << " atotal,btotal: " << atotal << " " << btotal<<endl;
        best = max(best,atotal+btotal);
    }
    cout << best << endl;

}
