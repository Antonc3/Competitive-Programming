#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a;
vector<vector<int>> g;
//child to parent
map<pair<int,int>,ll> mp;
vector<int> treeSize;
vector<ll> ans;
int n;

void dfs(int cur, int par){
    treeSize[cur] = 1;
    mp[{cur,par}] = 0;
    for(int to : g[cur]){
        if(to==par) continue;
        dfs(to,cur);
        treeSize[cur] += treeSize[to];
        mp[{cur,par}] += mp[{to,cur}];
    }
    if(par==-1) return;
    mp[{cur,par}] += 1ll*treeSize[cur] * (a[cur]^a[par]);
}

void dfs2(int cur, int par){
    ll parWeight = (par != -1) ? mp[{par,cur}] : 0;
    for(int to : g[cur]){
        if(to == par) continue;
        parWeight += mp[{to,cur}];
    }
    for(int to : g[cur]){
        if(to==par) continue;
        int parSize = n-treeSize[to];
        mp[{cur,to}] = parWeight-mp[{to,cur}]+1ll*(a[cur]^a[to])*parSize;
        dfs2(to,cur);
    }
    ans[cur] = parWeight;
}

void solve(){
    cin >> n;
    a.resize(n);
    g.resize(n);
    treeSize.resize(n);
    ans.resize(n);
    mp.clear();
    for(int i = 0; i < n; i++){
        cin >> a[i];
        g[i].clear();
    }
    for(int i =0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1);
    dfs2(0,-1);
    for(ll i : ans) cout << i << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}