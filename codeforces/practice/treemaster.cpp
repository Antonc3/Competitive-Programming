#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005


unordered_map<int,ll> mp[MAXN];

int n,q;
vector<ll> a;
vector<int> p;
ll dfs(int b, int c, int d){
    if(b==0) return 0;
    if(b > c) swap(b,c);
    if(mp[b].count(c) > 0){
        return mp[b][c];
    }
    ll cur = a[b]*a[c]+dfs(p[b],p[c],d+1);
    if(d == 325) mp[b][c] = cur;
    return cur;
}
int main(){
    cin >> n >> q;
    a.resize(n+1);
    p.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) cin >> p[i];
    for(int i = 0; i < q; i++){
        int b,c;
        cin >> b >> c;
        ll ans = dfs(b,c,0);
        cout << ans<<endl;
    }
}
