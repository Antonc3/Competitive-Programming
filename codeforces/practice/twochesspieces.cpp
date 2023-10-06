#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,d;
vector<vector<int>> adj;
vector<int> a,b;
vector<int> depth;
ll totalCost = 0;
int adepth,bdepth;
void dfs(int cur, int par){
    if(a[cur]){
        totalCost += depth[cur]-adepth;
        adepth = depth[cur];
        if(adepth-bdepth > d){
            //want it so that bdepth = adepth-d
            totalCost+= adepth-bdepth-d;
            bdepth = adepth-d;
        }
    }
    
    if(b[cur]){
        totalCost += depth[cur]-bdepth;
        bdepth = depth[cur];
        if(bdepth-adepth > d){
            //want it so that bdepth = adepth-d
            totalCost+= bdepth-adepth-d;
            adepth = bdepth-d;
        }
    }
    for(int to : adj[cur]){
        if(to==par){
            continue;
        }
        depth[to] = depth[cur] + 1;
        dfs(to,cur);
    }
    if(adepth != 0 && adepth == depth[cur]){
        totalCost++;
        adepth--;
    }
    if(bdepth != 0 && bdepth == depth[cur]){
        totalCost++;
        bdepth--;
    }
}

void solve(){
    cin >> n >> d;
    adepth = 0, bdepth = 0;
    depth.resize(n,0);
    adj.resize(n);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int m1;
    cin >> m1;
    a.resize(n);
    for(int i = 0; i <m1; i++){
        int x;
        cin >> x;
        --x;
        a[x] = 1;
    }
    cin >> m1;
    b.resize(n);
    for(int i = 0; i <m1; i++){
        int x;
        cin >> x;
        --x;
        b[x] = 1;
    }
    totalCost= 0;
    dfs(0,-1);
    cout << totalCost << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}