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

const bool DEBUG = false;

pii dfs(int cur, vector<vector<pii>> &adj, vi &par, vi &visited){
    visited[cur] = true;
    for(auto to : adj[cur]){
        if(to.first == par[cur]) continue;
        par[to.first] = cur;
        if(visited[to.first]) return {cur,to.first};
        pii res = dfs(to.first,adj,par,visited);
        if(res.first != -1) return res;
    }
    return {-1,-1};
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    vector<pii> edges(m);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        edges[i] = {a,b};
        adj[a].pb(make_pair(b,i));
        adj[b].pb(make_pair(a,i));
    }
    int numcycles = m-(n-1);
    if(DEBUG) cout << "numcycles: " << numcycles << "\n";
    vi color(m,0);
    vi vertices(n,0);
    rep(j,0,numcycles){
        if(DEBUG)cout << "j: " << j <<'\n';
        vi visited(n,0);
        vi par(n,-1);
        pii res = dfs(0,adj,par,visited);
        int v1 = res.first;
        int v2 = res.second;
        if(DEBUG) cout << "v1: "<< v1 <<" v2: " << v2 <<"\n";
        if(vertices[v1] && vertices[v2]){
            v2 = v1;
            v1 = par[v1];
        }
        vertices[v1] = vertices[v2] = 1;
        for(auto &edge : adj[v1]){
            if(edge.first == v2){
                color[edge.second] = 1;
                swap(edge,adj[v1].back());
                adj[v1].pop_back();
                break;
            }
        }
        for(auto &edge : adj[v2]){
            if(edge.first == v1){
                swap(edge,adj[v2].back());
                adj[v2].pop_back();
                break;
            }
        }
    }
    for(auto i : color){
        cout << i;
    }
    cout << "\n";
}

int main() {
	if(!DEBUG)cin.tie(0)->sync_with_stdio(0);
	if(!DEBUG)cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
