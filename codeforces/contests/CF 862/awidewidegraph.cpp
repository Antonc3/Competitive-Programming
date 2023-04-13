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

vector<vi> g;
int n;
vi ans;
vi dist1;
vi dist2;
void dfs1(int cur, int par=-1){
    for(auto to : g[cur]){
        if(par==to) continue;
        dist1[to] = dist1[cur]+1;
        dfs1(to,cur);
    }
}
void dfs2(int cur, int par=-1){
    for(auto to : g[cur]){
        if(par==to) continue;
        dist2[to] = dist2[cur]+1;
        dfs2(to,cur);
    }
}

void solve(){
    cin >> n;
    g.resize(n);
    ans.resize(n);
    dist1.resize(n,0);
    dist2.resize(n,0);
    rep(i,0,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(0);
    pii best = {0,0};
    rep(i,0,n) best = max(best,{dist1[i],i});
    dist1[best.second] = 0;
    dfs1(best.second);
    best = {0,0};
    rep(i,0,n) best = max(best,{dist1[i],i});
    dfs2(best.second);
    rep(i,0,n){
        ans[max(dist1[i],dist2[i])]++;
    }
    int cnt = 1;
    rep(i,0,n){
        cnt+=ans[i];
        cout << min(n,cnt) << " ";
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
