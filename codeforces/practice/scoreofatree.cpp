#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll M =1e9+7;

// 2^n-1 * n
//

ll fastpow(ll b, ll e){
    ll res =1;
    while(e >  0){
        if(e&1) res= (res*b)%M;
        b = (b*b)%M;
        e/=2;
    }
    return res;
}

vector<vector<int>> g;
vector<int> depth;
int n;
ll ans;
void dfs1(int cur, int prev){
    depth[cur] = 0;
    for(int to : g[cur]){
        if(to==prev) continue;
        dfs1(to,cur);
        depth[cur] = max(depth[to]+1,depth[cur]);
    }
    ans = (ans+1ll*(depth[cur]+1)*fastpow(2,n-1))%M;
}

void solve(){
    cin >> n;
    ans= 0;
    g.resize(n);
    depth.resize(n,1);
    for(int i = 0; i < n; i++) g[i].clear();
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(0,-1);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}