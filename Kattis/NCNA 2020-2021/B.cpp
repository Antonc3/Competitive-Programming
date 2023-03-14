#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXK 1005
#define f first
#define s second
typedef pair<int,int> pii;
int n,m,k;
int mat[MAXN][MAXN];
vector<pair<int,pii>> queries;
vector<pii> endtime;
int dfs(int last,int time){
    for(int i = 0; i < endtime.size(); i++){
        int ei = endtime[i].s;
        //endtime.f = queries[ei].f+mat[queries[ei].s.f][queries[ei].s.s]
        int moveDist = 0;
        if(last != -1){
            moveDist = mat[last][queries[ei].s.f];
        }
        if(queries[ei].f >= time+moveDist){
            //pickup
            int etime = endtime[i].f;
            endtime.erase(endtime.begin()+i);
            return 1+dfs(queries[ei].s.s,etime);
        }
    }
    return 0;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            mat[i][j] = 10000000;
        }
    }
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        mat[u][v] = w;
    }
    for(int i =0; i < k; i++){
        int u,v,t;
        cin >> u >> v >>t;
        queries.push_back({t,{u,v}});
    }
    for(int k = 0; k <= n; k++){
        for(int i = 0; i <=n; i++){
            for(int j = 0; j <=n; j++){
                if(mat[i][k]+mat[k][j] < mat[i][j]){
                    mat[i][j] = mat[i][k]+mat[k][j];
                }
            }
        }
    }
    for(int i = 0; i < queries.size(); i++){
        pair<int,pair<int,int>> cur = queries[i];
        // cout <<"distance from u to v" << mat[cur.s.f][cur.s.s] << endl;
        endtime.push_back({cur.f+mat[cur.s.f][cur.s.s],i});
    }
    sort(endtime.begin(),endtime.end());
    int ans = 0;
    while(!endtime.empty()){
        dfs(-1,0);
        ans++;
    }
    cout << ans<<endl;
}