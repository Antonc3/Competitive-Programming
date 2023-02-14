#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
const int INF = 1e9;
vector<int> g[MAXN];
int dist[MAXN];
bool color[MAXN];
int best;

void dfs(int cur, int par){
    if(best <= dist[cur]) return;
    if(color[cur]) best = min(best,dist[cur]);
    for(int i : g[cur]){
        if(i == par) continue;
        best = min(best,dist[i]+dist[cur]+1);
        if(dist[i] <= dist[cur]+1) continue;
        dist[i] = dist[cur]+1;
        dfs(i,cur);
    }
}

// void updateDist(int toUpdate){
//     queue<array<int,2>> q;
//     q.push({toUpdate,-1});
//     dist[toUpdate] = 0;
//     while(!q.empty()){
//         auto &[cur, par] = q.front();
//         q.pop();
//         if(dist[cur] >= best) return;
//         for(int i : g[cur]){
//             if(i==par) continue;
//             best = min(best, dist[cur] + dist[i]+1);
//             if(dist[i] < dist[cur]+1) continue;
//             dist[i] = dist[cur]+1;
//             q.push({i,cur});
//         }
//     }
// }
void solve(){
    int n;
    cin >> n;
    vector<int> order(n);
    for(int i = 0; i < n; i++) g[i].clear();
    memset(color,0,n);
    fill(dist,dist+n+1,INF);
    for(int &x : order) {cin >> x; x--;}
    // for(int x : order) cout << x << " ";
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    best = INF;
    dist[order[0]] = 0;
    dfs(order[0],-1);
    color[order[0]] = true;
    // cout << "n: " << n;
    vector<int> ans;
    for(int i = 1; i < n; i++){
        dist[order[i]] = 0;
        dfs(order[i],-1);
        color[order[i]] = true;
        ans.push_back(best);
    }
    for(int i : ans) cout << i << " ";
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}