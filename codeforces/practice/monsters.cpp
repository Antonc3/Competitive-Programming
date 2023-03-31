#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct dsu{
    vi par;
    vi s;
    vector<priority_queue<pii>> edges;

    void init(int n,vector<vector<int>> &g, vector<int> &danger){
        par.resize(n);
        s.resize(n,1);
        edges.resize(n);
        rep(i,0,n){
            par[i] = i;
            for(auto edge : g[i]){
                edges[i].push({-danger[edge],edge});
            }
        }
    }
    int get(int a){
        if(a==par[a]) return a;
        return par[a] = get(par[a]);
    }
    void join(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(s[a] > s[b]) swap(a,b);
        par[a] = b;
        s[b] += s[a];
        while(edges[a].size()){
            auto cur = edges[a].top();
            edges[a].pop();
            edges[b].push(cur);
        }
    }
};

void solve(){
    int n,m;
    cin >> n >> m;
    vi danger(n);
    vi starts;
    rep(i,0,n){
        cin >> danger[i];
        if(danger[i]==0) starts.push_back(i);
    }
    vector<vi> g(n+1,vi());
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi visited(n,0);
    dsu d;
    d.init(n,g,danger);
    for(auto start : starts){
        //cout << "start: " << start << "\n";

        while(!d.edges[d.get(start)].empty()){
            int curgroup = d.get(start);
            auto cur = d.edges[curgroup].top();
            int cdanger = -cur.first;
            int curloc = cur.second;
            if(cdanger > d.s[curgroup]) break;
            d.edges[curgroup].pop();
            //cout << "looking at : " <<cdanger << " " << cur.second <<"\n";
            //cout << "current defeated: " << d.sz[d.get(start)]<<"\n";
            d.join(curloc,start);
        }
    }
    if(d.s[d.get(0)] == n) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
