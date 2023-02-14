#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define INF 1e9
int n,m;
int g[51][51];
double dist[51][51];
double eps = 1e-8;

bool DEBUG = false;
bool checkPath(int r1, int c1, int r2, int c2){
    double dc = ((double) c2-(double) c1)/((double) r2-(double) r1);
    double dr = ((double) r2-(double) r1)/((double) c2-(double) c1);
    double sc = (double) c1;
    double sr = (double) r1;
    // if(r2==2 && c2==3){
    //     DEBUG = true;
    //     cout << "dc: " << dc << " dr: " << dr << endl;
    // }
    if(DEBUG) cout << "checking from: " << r1 << " " << c1 << " to: " << r2 << " " << c2<<endl;
    if(DEBUG) cout << "dc: " << dc << " dr: " << dr<<endl;
    while(sc < (double) c2 && sr < (double) r2){
        if(DEBUG) cout << "sr: " << sr << " sc: " << sc<<endl;
        int curR = floor(sr);
        int curC = floor(sc);
        
        double remR = 1.0-(sr-curR);

        double remC = 1.0-(sc-curC);
        if(DEBUG) cout << "remR: " << remR << " remC: " << remC << endl;
        if(g[curR][curC]) return false;
        //r + 1, col + dr
        //c + 1, r + dc
        //if adding

        if(sr+remC*dr-(double) curR < 1.0){
            sc=(double) curC+1;
            sr+=remC*dr;
        }
        else{
            sr=(double) curR+1;
            sc+=remR*dc;
        }
    }
    return true;
}

void djikstra(){
    priority_queue<pair<double,pair<int,int>>> pq;
    pq.push({0.0,{0,0}});
    dist[0][0] = 0.0;
    vector<vector<int> > visited = vector<vector<int> >(n+2,vector<int>(m+2,0));
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int r = cur.S.F;
        int c = cur.S.S;
        if(visited[r][c] || -cur.F > dist[r][c]){
            // cout << "r c: " << r << " " << c << endl;
            continue;
        }
        visited[r][c] = true;
        if(DEBUG) cout << "r c: " << r << " " << c << endl;
        for(int rr = r; rr <= n; rr++){
            for(int cc = c; cc <= m; cc++){
                if(rr==r && cc==c) continue;
                double distToAdd = sqrt((rr-r)*(rr-r)+(cc-c)*(cc-c));
                if(dist[rr][cc]+eps <= dist[r][c]+distToAdd) continue;
                if(rr==r || cc==c || checkPath(r,c,rr,cc)){
                    if(DEBUG) cout << "going to rr cc: " << rr << " " << cc << endl;
                    if(DEBUG) cout << "distToAdd: " << distToAdd<<endl;
                    if(DEBUG) cout << "dist[rr][cc]: " << dist[rr][cc] << " dist[r][c]: " << dist[r][c] << endl;
                    visited[rr][cc] = false;
                    dist[rr][cc] = dist[r][c]+distToAdd;
                    pq.push({-(dist[r][c]+distToAdd),{rr,cc}});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            char c;
            cin >> c;
            if(c=='#') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            dist[i][j] = (double) INF;
        }
    }

    djikstra();
    cout << setprecision(10)<< fixed << dist[n][m];
}