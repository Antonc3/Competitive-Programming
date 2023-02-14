#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define F first
#define S second
typedef pair<int,int> pii;
bool DEBUG = false;


int m,n;
vector<int> adj[MAXN*MAXN];
char maze[MAXN][MAXN];
vector<int> entrances;
int mapto(int y,int x){
    return y*m+x;
}
pii unmap(int val){
    return {val%m, (val-val%m)/m};
}
bool visited[MAXN*MAXN];

int dfs(int cur){
    int seenDots = 0;
    for(int a : adj[cur]){
        if(DEBUG) cout << "cur: " << cur << " to: " << a << endl;
        if(!visited[a]){
            pii acords = unmap(a);
            if(maze[acords.S][acords.F]=='.'){
                seenDots++;
            }
            visited[a] = true;
            seenDots+=dfs(a);
        }
    }
    return seenDots;
}

int main(){
   
    cin >> n >> m;
    fill(visited, visited+sizeof(visited)/sizeof(visited[0]), false);
    int dots = 0;
    string adsfsaf;
    getline(cin,adsfsaf);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        // if(DEBUG) cout << s << endl;
        for(int j = 0;j < m; j++){
            char c = s[j];
            maze[i][j] = c;
            if(c=='.') dots++;
        }
    }
    if(DEBUG) cout << "Done reading input!\n";
    int dir[] = {0,1,0,-1};
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            char cur = maze[i][j];
            if(cur=='X'){
                continue;
            }
            else if(cur != ' ' && cur != '.'){
                entrances.push_back(mapto(i,j));
            }
            for(int d = 0; d < 4; d++){ 
                int ny = i+ dir[(d+1)%4];
                int nx = j+dir[d];
                if(nx < 0 || nx >= m || ny >= n || ny < 0) continue;
                
                if(maze[ny][nx] == '.' || maze[ny][nx] == ' '){
                    if(DEBUG){
                        cout << "I, j: " << i << ", " << j<<endl;
                        cout << "ny, nx " << ny << ", " << nx<<endl;
                    }
                    if(DEBUG) cout << "adding edge from " << mapto(i,j) << " to " << mapto(ny,nx)<<endl;
            
                    adj[mapto(i,j)].push_back(mapto(ny,nx));
                }
            } 
        }
    }
    if(DEBUG) cout << "Done processing input\n";
    int totalSeenDots = 0;
    int usedPlayers = 0;
    for(int i : entrances){
        if(visited[i]) continue;
        visited[i] = true;
        if(DEBUG) cout << "Using entrance: " << i << endl;
        int seenDots = dfs(i);
        if(seenDots > 0){
            usedPlayers++;
        }
        totalSeenDots+=seenDots;
    }
    if(DEBUG) cout << "totalSeenDots: " << totalSeenDots << ", total Dots: " << dots << endl;
    cout << usedPlayers << " " << dots-totalSeenDots<<endl;

}