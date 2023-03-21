#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
struct edge{
    int to, w, i;
};

int dfs(vector<int> &cnt,vector<vector<edge>> &adj, int c, edge p){
    //cout << "c: " << c << endl;
    bool leaf = true;
    int sum = 0;
    for(auto i : adj[c]){
        if(i.i == p.i) continue;
        leaf = false;
        cnt[i.i] = dfs(cnt,adj,i.to,i);
        sum+=cnt[i.i];
    }
    if(leaf) return 1;
    return sum;
}
void solve(){
    ll S;
    int n;
    cin >> n >> S;
    vector<vector<edge>> adj(n,vector<edge>());
    vector<int> edges(n-1);
    for(int i = 0; i < n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        edges[i] = c;
        adj[a].push_back({b,c,i});
        adj[b].push_back({a,c,i});
    }
    vector<int> cnt(n-1,0);
    dfs(cnt,adj,0,{-1,-1,-1});
    ll sum = 0;
    priority_queue<pair<ll,int>> pq;
    for(int i = 0; i < n-1; i++){
        //cout << " i: " << cnt[i] << endl;
        sum+=1ll*cnt[i]*edges[i];
        pq.push({1ll*cnt[i]*(1ll*(edges[i]+(edges[i]&1))/2),i});
        //cout << (edges[i]+(edges[i]&1))<<endl;
    }
    ll moves = 0;
    while(sum > S){
        //cout << sum << endl;
        auto cur = pq.top();
        pq.pop();
        sum-=cur.F;
        edges[cur.S]/=2;
        moves++;
        pq.push({1ll*cnt[cur.S]*((1ll*edges[cur.S]+(edges[cur.S]&1))/2),cur.S});
    }
    cout << moves << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
