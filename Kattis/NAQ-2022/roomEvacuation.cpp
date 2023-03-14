#include <bits/stdc++.h>
using namespace std;
#define MAXN 161005

bool DEBUG = false;
int n,m,t;

struct edge{
    int c,f,dest;
};

vector<vector<edge>> adj;

char room[25][25];

void addEdge(int a, int b, int w){
    // if(DEBUG) cout << "adding edge from: " << a << " to "<< b<<endl;
    adj[a].push_back({w,0,b});
    adj[b].push_back({0,0,a});
}
int mapTo(int y, int x, int tm){
    // if(DEBUG) cout << "mapto: " << "y: " << y << " x: " << x << " time: " << tm << endl;
    // return 1+2*(((y*m)+x)*t+tm);
    return 1+ 2*(((tm*m)+x)*n+y);
}

bool bfs(vector<int> &v){
    v = vector<int>(MAXN,MAXN);
    queue<int> q;
    q.push(0);
    v[0] = -1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        // if(DEBUG) cout << "cur: " << cur << endl;
        for(auto ed : adj[cur]){
            if(ed.c-ed.f > 0 && v[ed.dest] == MAXN){
                // if(DEBUG) cout << "edge: " << ed.dest<<endl;
                v[ed.dest] = cur;
                q.push(ed.dest);
                if(ed.dest == MAXN-1) return true;
            }
        }
    }
    return v[MAXN-1] != MAXN;
}

int augment(vector<int> &v){
    if(DEBUG) cout << "PUSHING FLOW!\n";
    if(DEBUG) cout << MAXN-1 << " ";
    for(int i = MAXN-1; v[i] != -1; i = v[i]){
        int from = v[i];
        if(DEBUG) cout << from << " ";
        int to = i;
        for(int i = 0; i < adj[from].size(); i++){
            if(adj[from][i].dest == to){
                adj[from][i].f = adj[from][i].f + 1;
            }
        } 
        for(int i = 0; i < adj[to].size(); i++){
            if(adj[to][i].dest == from){
                adj[to][i].f = adj[to][i].f - 1;
            }
        }
    }
    if(DEBUG) cout << endl;
    return 1;
}

int maxFlow(){
    vector<int> v;
    int totFlow = 0;
    while(bfs(v)){
        if(DEBUG) cout << totFlow<<endl;
        totFlow+=augment(v);
    }
    return totFlow;
}

int main(){
    cin >> n >> m >> t;
    string afadsfas;
    getline(cin,afadsfas);
    adj.resize(MAXN);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        if(DEBUG) cout << "S: " << s << " i: " << i << endl;
        for(int j = 0; j < m; j++){
            room[i][j] = s[j];
        }
    }
    if(DEBUG) cout <<"DONE READING INPUT\n";
    int dir[] = {0,1,0,-1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(DEBUG) cout << "i, j: " << i << " " << j << endl;
            if(room[i][j] == '#') continue;
            for(int tt = 0; tt < t; tt++){
                addEdge(mapTo(i,j,tt),mapTo(i,j,tt)+1,1);
                addEdge(mapTo(i,j,tt)+1,mapTo(i,j,tt+1),1);
            }
            addEdge(mapTo(i,j,t),mapTo(i,j,t)+1,1);

            if(room[i][j] == 'P'){
                addEdge(0,mapTo(i,j,0),1);
            }
            if(room[i][j] == 'E'){
                for(int tt = 1; tt <= t; tt++){
                    addEdge(mapTo(i,j,tt)+1,MAXN-1,1)   ;
                }
            }
            for(int d = 0; d < 4; d++){
                int nx = j+dir[d];
                int ny = i+dir[(d+1)%4];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || room[ny][nx] == '#'){
                    continue;
                }
                // if(DEBUG) cout << "i, j: " << i << " " << j << " ny nx: " << ny << " " << nx << endl;
                int st = 0;
                for(int tt = st; tt < t; tt++){
                    addEdge(mapTo(i,j,tt)+1,mapTo(ny,nx,tt+1),1);
                }
            }
            
        }
    }
    if(DEBUG) cout << "DONE PROCESSING INPUT\n";
    if(DEBUG){
        for(int i = 0; i < 2+2*n*(t+2)*m;i++){
            cout << "from: " << i << " - ";
            for(auto e : adj[i]){
                cout << e.dest << " ";
            }
            cout << endl;
        }
    }
    cout << maxFlow()<<endl;
}
/*
10 10 10
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPP###PPP
PPPP#E#PPP
PPPP###PPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP
PPPPPPPPPP

1 10 4
E...PP...E

#
*/