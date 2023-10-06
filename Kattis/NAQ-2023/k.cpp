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


struct dsu{
    vector<int> S;
    vector<int> val;
    dsu(int n){
        S.resize(n,-1);
        val.resize(n);
        for(int i =0 ; i < n; i++){
            S[i] = -1;
            val[i] = i;
        }
    }
    void setVal(int a, int v){
        val[get(a)] = v;
    }
    int getVal(int a){
        return val[get(a)];
    }
    int get(int a){
        if(S[a] < 0) return a;
        return S[a] = get(S[a]);
    }
    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        int bVal = val[b];
        if(a==b) return false;
        if(a > b) swap(a,b);
        S[a] += S[b];
        S[b] = a;
        val[a] = bVal;
        return true;
    }
};

int n,m;
vector<vector<pair<int,int>>> g;
vector<vector<pair<int,int>>> mst;
vector<pair<int,int>> fath;
vector<int> depth;

void dfs1(int cur, int par){
    for(auto [to,w] : mst[cur]){
        if(to==par) continue;
        fath[to] ={cur,w};
        depth[to] = depth[cur]+1;
        dfs1(to,cur);
    }
}

void solve(){
    cin >> n >> m;
    g.resize(n);
    mst.resize(n);
    fath.resize(n);
    depth.resize(n,0);
    dsu d(n);
    priority_queue<tuple<int,int,int>> pq;
    for(int i = 0; i < m; i++){
        int a,b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        pq.push({-w,a,b});
    }
    ll bestScore = 0;
    vector<tuple<int,int,int>> notInMST;
    while(!pq.empty()){
        auto [w,a,b] = pq.top();
        w = -w;
        pq.pop();
        if(!d.unite(a,b)){
            notInMST.push_back({w,a,b});
            continue;
        }
        bestScore+=w;
        mst[a].push_back({b,w});
        mst[b].push_back({a,w});
    }
    depth[0]=0;
    fath[0] = {-1,-1};
    dfs1(0,-1);
    ll ans = bestScore;
    dsu dsu2(n);
    for(auto [w,a,b] : notInMST){
        //find lca;
        //also find current min along the way
        ll curMin = 1e9;
        int aa = a, bb = b;
        while(aa != bb){
            if(dsu2.getVal(aa) != aa){
                aa=dsu2.getVal(aa);
                continue;
            }
            if(dsu2.getVal(bb) != bb){
                bb=dsu2.getVal(bb);
                continue;
            }
            if(depth[aa] > depth[bb]){
                curMin = min(curMin,1ll*fath[aa].second);
                dsu2.unite(aa,fath[aa].first);
                aa = fath[aa].first;
            }
            else if(depth[bb] > depth[aa]){
                curMin = min(curMin,1ll*fath[bb].second);
                dsu2.unite(bb,fath[bb].first);
                bb = fath[bb].first;
            }
            else{
                dsu2.unite(bb,fath[bb].first);
                dsu2.unite(aa,fath[aa].first);
                curMin = min(curMin,1ll*fath[aa].second);
                curMin = min(curMin,1ll*fath[bb].second);
                aa = fath[aa].first;
                bb = fath[bb].first;
            }
        }
        ans = max(ans,bestScore-curMin+w);
    }
    cout << ans<<endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
