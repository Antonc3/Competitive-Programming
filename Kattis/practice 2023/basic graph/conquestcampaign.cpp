#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> visited(r,vector<int>(c,-1));
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        --x; --y;
        visited[x][y] = 1;
        q.emplace(x,y);
    }
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    int best = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(visited[nx][ny] != -1) continue;
            visited[nx][ny] = visited[cur.first][cur.second]+1;
            best = max(best,visited[nx][ny]);
            q.emplace(nx,ny);
        }
    }
    cout << best << endl;
}