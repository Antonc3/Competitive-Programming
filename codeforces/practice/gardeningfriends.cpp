#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

void dfs(int cur,int par,vi &dist, vector<vi> &adj){
    for(int i : adj[cur]){
        if(i==par) continue;
        dist[i] = dist[cur]+1;
        dfs(i,cur,dist,adj);
    }
}

pii dfs3(int cur, int par, vector<set<pii>> &best,vector<vi> &adj){
    pii a = {0,cur};
    for(int i : adj[cur]){
        if(i==par) continue;
        pii found = dfs3(i,cur,best,adj);
        found = {found.first+1,i};
        best[cur].insert(found);
        a = max(found,a);
    }
    return a;
}

void dfs2(int cur,int par,int frompar,vector<set<pii>> &best,vi &dist, vector<vi> &adj){
    for(int i : adj[cur]){
        if(i==par) continue;
        dist[i] = dist[cur]+1;
        int fromcuraspar = frompar;
        for(auto j = best[cur].rbegin(); j != best[cur].rend(); j++){
            if((*j).second == i) continue;
            fromcuraspar = max(fromcuraspar,(*j).first); 
            break;
        }
        //cout << "i: " << i << " fromcuraspar " << fromcuraspar<<"\n";
        dfs2(i,cur,fromcuraspar+1,best,dist,adj);
    }
    dist[cur] = frompar;
    if(best[cur].empty()) return;
    dist[cur] = max(frompar,best[cur].rbegin()->first);
}

void solve(){
    int n,k,c;
    cin >> n >> k >> c;
    vector<vi> adj(n+1,vi());
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> dist1(n+1);
    dist1[0] = 0;
    vector<int> maxcost(n+1); 
    vector<set<pii>> best(n+1);
    dfs(0,-1,dist1,adj);
    dfs3(0,-1,best,adj);
    dfs2(0,-1,-1,best,maxcost,adj);
    ll ans = 0;
    rep(i,0,n){
        ans = max(ans,1ll*maxcost[i]*k-1ll*dist1[i]*c);
        //cout << "cost: " << maxcost[i] << " dist: " << dist1[i] <<"\n";
    }
    cout <<ans<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
