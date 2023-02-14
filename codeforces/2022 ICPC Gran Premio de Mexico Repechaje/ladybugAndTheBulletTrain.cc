#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010    

const bool DEBUG = false;

int n,m;

vector<int> adj[MAXN];

vector<int> shortestPath;
vector<int> sp;
void bfs(){
    shortestPath = vector<int>(n+5,MAXN);
    queue<int> q;
    q.push(1);
    shortestPath[1] = -1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int e : adj[cur]){
            if(shortestPath[e] == MAXN){
                q.push(e);
                shortestPath[e] = cur;
                if(e == m){
                    return;
                }
            }
        }
    }
}

int dfs(int cur, int par, int spInd){
    int tot = 0;
    bool ontrack = false;
    for(int ed: adj[cur]){
        if(ed == par){
            continue;
        }
        if(ed == m){
            return 1;
        }
        if(ed == sp[spInd]){
            ontrack = true;
            continue;
        }
        tot+=2+dfs(ed,cur,spInd);
    }
    if(ontrack){
        tot+=1+dfs(sp[spInd],cur,spInd+1);        
    }

    return tot;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(DEBUG) cout << "done reading inp\n";
    bfs();
    if(DEBUG) cout << "done with bfs\n";
    for(int i = m; i != -1; i = shortestPath[i]){
        sp.push_back(i);
    }
    reverse(sp.begin(),sp.end());
    cout << dfs(1,0,1);
}