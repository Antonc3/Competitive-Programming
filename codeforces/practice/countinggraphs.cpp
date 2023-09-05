#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct dsu{
    vector<ll> S;
    void init(int n){
        S.resize(n,-1ll);
    }
    ll size(int x){
        return -S[get(x)];
    }
    int get(int x){
        return (S[x] > 0ll) ? S[x] = (ll) get(S[x]) : x;
    }
    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return false;
        if(-S[a] > -S[b]) swap (a,b);
        S[b]+=S[a];
        S[a] = b;
        return true;
    }
};

const ll M = 998244353;

ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = (res*b)%M;
        b = (b*b)%M;
        e/=2;
    }
    return res;
}
void solve(){
    int n;
    ll S;
    cin >> n >> S;
    vector<tuple<ll,int,int>> edges;
    for(int i =0; i < n-1; i++){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(w,--u,--v);
    }
    sort(edges.begin(),edges.end());
    ll ans = 1;
    dsu d;
    d.init(n);
    for(auto [w, u, v] : edges){
        ll usize = d.size(u);
        ll vsize = d.size(v);
        
        ans = (ans*fastpow(S-w+1,usize*vsize-1))%M;
        d.unite(u,v);
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