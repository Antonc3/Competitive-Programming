#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005
typedef long long ll;

int n, m, w;
int board[MAXN][MAXN];
ll cost[MAXN][MAXN][2];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void solve(){
    cin >> n >> m >> w;
    vector<pair<int,int>> portals;
    for(int i =0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            cost[i][j][0] = -1;
            cost[i][j][1] = -1;
            if(board[i][j] > 0){
                portals.push_back({i,j});
            }
        }
    }
    queue<tuple<int,int,int>> q;
    cost[0][0][0] = 0;
    cost[n-1][m-1][1] = 0;
    q.push({0,0,0});
    q.push({n-1,m-1,1});
    while(!q.empty()){
        auto [cy, cx,k] = q.front(); 
        q.pop();
        ll curCost = cost[cy][cx][k];
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (cost[ny][nx][k] <= curCost + w && cost[ny][nx][k] != -1)
                continue;
            if(board[ny][nx] == -1) continue;
            cost[ny][nx][k] = curCost+w;
            q.push({ny,nx,k});
        }
    }
    int ok = (cost[0][0][1] != -1);
    ll ans = (ok) ? cost[0][0][1] : 1e18;
    ll minCostTo = 1e18;
    ll minCostFrom = 1e18;
    for(auto [y1,x1] : portals){
        if(cost[y1][x1][0] != -1){
            ll cost1 = cost[y1][x1][0] + board[y1][x1];
            minCostTo = min(minCostTo,cost1);
        } 
        if(cost[y1][x1][1] != -1){
            ll cost1 = cost[y1][x1][1] + board[y1][x1];
            minCostFrom = min(minCostFrom,cost1);
        } 
    }
    if(minCostTo < 1e18 && minCostFrom < 1e18) ok = 1;
    ans = min(ans,minCostFrom+minCostTo);
    if(ok){
        cout << ans << endl;
    }
    else{
        cout << "-1\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}