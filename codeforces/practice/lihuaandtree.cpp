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
const int MAXN = 1e5+5;

int a[MAXN];
ll importance[MAXN];
set<pair<ll,int>> importances[MAXN];
int sizes[MAXN];
vi g[MAXN];
int father[MAXN];
int n,m;

void rotate(int x){
    if(sizes[x] == 1) return;
    auto heaviestson = *importances[x].rbegin();
    int hs = -heaviestson.second;
    int par = father[x];
    importances[par].erase({sizes[x],-x});
    importances[par].insert({sizes[x],-hs});
    importances[x].erase({sizes[hs],-hs});
    //size of father remains unchanged
    // size of hs should be previous size of x
    // size of x should be size of x - previous size of hs
    // importance of hs should be prev importance of x
    // importance of x should be prev importance of x - prev importance of hs
    sizes[x] -= sizes[hs];
    sizes[hs]+=sizes[x];
    importance[x] -= importance[hs];
    importance[hs] += importance[x];
    importances[hs].insert({sizes[x],-x});
    father[x] = hs;
    father[hs] = par;
}

void dfs1(int cur, int par){
    father[cur] =par;
    sizes[cur] = 1;
    importance[cur] += a[cur];
    for(auto edge : g[cur]){
        if(edge == par) continue;
        dfs1(edge,cur);
        sizes[cur] += sizes[edge];
        importance[cur] += importance[edge];
        importances[cur].insert({sizes[edge],-edge});
    }
}

void solve(){
    cin >> n >> m;
    rep(i,0,n){
        cin >> importance[i];
    }
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0,-1);
    rep(i,0,m){
        int op, ind;
        cin >> op >> ind;
        ind--;
        if(op==1) cout << importance[ind]<<"\n";
        else {
            rotate(ind);
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
