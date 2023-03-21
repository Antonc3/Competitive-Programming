#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define INF 2e9
const bool DEBUG = false;

int n,m;
int p,b;
vector<int> adj[MAXN];
bool token[MAXN];
bool bonus[MAXN];
vector<int> dist;

void bfs(){
    //start from node 1;
    dist = vector<int>(n+2,INF);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int ed : adj[cur]){
            if(dist[ed] <= dist[cur]+1) continue;
            if(dist[ed] > dist[cur]+1) dist[ed] = dist[cur]+1;  
            if(!bonus[ed]) continue;
            q.push(ed);
        }
    }
}

int getNearest(int cur){
    int res = 0;
    for(auto fir : adj[cur]){
        if(!bonus[fir]) continue;
        res = 1;
        for(auto sec : adj[fir]){
            if(bonus[sec]) return 2;
        }
    }
    return res;
}


void solve(){
    cin >> n >> m;
    cin >> p >> b;
    vector<int> tokenList;
    fill(token,token+n+1,false);
    fill(bonus,bonus+n+1,false);
    for(int i = 0; i <= n+1; i++){
        adj[i].clear();
    }
    for(int i = 0; i < p; i++){
        int a;
        cin >> a;
        token[a] = true;
        tokenList.push_back(a);
    }
    if(DEBUG) cout << "done reading tokesn\n";
    for(int i = 0; i < b; i++){
        int a;
        cin >> a;
        bonus[a] = true;
    }
    if(DEBUG) cout << "done reading bonus!\n";
    for(int i = 0; i < m; i++){
        int a,zz;
        cin >> a >> zz;
        adj[a].push_back(zz);
        adj[zz].push_back(a);
    }
    if(DEBUG) cout << "done reading input!\n";
    bfs();
    set<int> great;
    set<int> ok;
    for(auto i : tokenList){
        int t2 = getNearest(i);
        if(t2==2){
            great.insert(i);
        }
        if(t2==1){
            ok.insert(i);
        }
    }
    bool ans = false;
    for(int i : tokenList){
        if(dist[i]==INF) continue;    
        if(great.size() && ((*great.begin()) != i || (*great.rbegin()) != i)) ans = true;
        int stall = ok.size();
        if(ok.count(i)) stall--;
        if(stall+1 >= dist[i]) ans = true; 
    }
    cout << ((ans) ? "YES" : "NO") << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}