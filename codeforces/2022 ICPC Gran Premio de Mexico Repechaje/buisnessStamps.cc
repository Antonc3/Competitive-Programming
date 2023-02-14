#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
typedef pair<int,int> pii;
#define F first
#define S second

const bool DEBUG = false;

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dir[] = {0,1,0,-1};
int n,m;
int sr, sc;
int er, ec;

bool bfs(int mask){
    if(!(1<<grid[er][ec] & mask) || !(1<<grid[sr][sc] & mask)) return false;
    fill(&visited[0][0], &visited[0][0]+sizeof(visited)/sizeof(visited[0][0]), false);
    queue<pii> q;
    q.push({sr,sc});
    visited[sr][sc] = true;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ni = cur.F + dir[i];
            int nj = cur.S + dir[(i+1)%4];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(visited[ni][nj] || !(1<<grid[ni][nj] & mask)) continue;
            visited[ni][nj] = true;
            q.push({ni,nj});
            if(ni == er && nj == ec) return true;
        }
    }
    return visited[er][ec];
}

void solve(){
    cin >> n >> m;
    cin >> sr >> sc;
    sr--; sc--;
    cin >> er >> ec;
    er--; ec--;
    if(DEBUG) cout << "sr sc: " << sr << " " << sc<<endl;
    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++){
            cin >> grid[i][j];
            grid[i][j]--;
        }
    }
    if(DEBUG) cout << "1<<sr 1<<sc: " << (1<<grid[sr][sc]) << " " << (1<<grid[er][ec])<<endl;
    int maxMask = 1024;
    int ans = 10;
    for(int i = 0; i <= maxMask; i++){
        int cnt = 0;
        for(int j = 0; j <= 10; j++){
            if(1<<j & i){
                cnt++;
            }
        }
        // if(DEBUG) cout << "i: " << i << " COUNT: " << cnt << endl;
        if(cnt >= ans) continue;
        if(bfs(i)){ 
            if(DEBUG) cout << "BFS found: " << i << " COUNT: " << cnt << endl;
            ans = min(ans,cnt);
        }
    }
    cout << ans << endl;    
}

int main(){
    solve();
}