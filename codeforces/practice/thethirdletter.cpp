#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll emp = 1ll<<60;

bool dfs(int v, vector<ll> &pos,vector<vector<pair<int,int>>> &g){
    if(pos[v] == emp){
        pos[v] = 0;
    }
    for(pair<int,int> nxt : g[v]){
        if(pos[nxt.first] == emp){
            pos[nxt.first] = pos[v]+nxt.second;
            if(!dfs(nxt.first,pos,g)){
                return false;
            }
        }
        else{
            if(pos[nxt.first] != pos[v]+nxt.second){
                return false;
            }
        }
    }
    return true;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i =0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        g[a].push_back({b,-d});
        g[b].push_back({a,d});
    }
    vector<ll> pos(n,emp);
    for(int i =0; i < n; i++){
        if(pos[i] == emp){
            if(!dfs(i,pos,g)){
                cout << "NO\n";
                return;
            }
        }
    }
    cout <<"YES\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}