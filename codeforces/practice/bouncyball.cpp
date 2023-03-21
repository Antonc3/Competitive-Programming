#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MAXN 25005

int n,m;
int yy1,x1,y2,x2;
map<string, int> mp;
pair<int,int> directions[4];
int getnexthorizontal[] = {1,0,3,2};
int getnextvertical[] = {2,3,0,1};
int getcorner[] = {3,2,1,0};

int gotonext(vector<vector<vector<int>>> &visited,int cy, int cx, int dir){
    if(visited[cy][cx][dir]) return -1;
    visited[cy][cx][dir] = 1;
    auto curdir = directions[dir];
    int stepstodest = (y2-cy)/directions[dir].F;
    if(stepstodest >= 0){
        if(directions[dir].S*stepstodest+cx == x2) return 0;
    }
    int stepstohorizontalwall = 0;
    if(curdir.S > 0){
        stepstohorizontalwall = m-cx;
    }
    else{
        stepstohorizontalwall = cx-1;
    }
    int stepstoverticalwall = 0;
    if(curdir.F > 0){
        stepstoverticalwall = n-cy;
    }
    else{
        stepstoverticalwall = cy-1;
    }
    if(stepstohorizontalwall==stepstoverticalwall){
        int res = gotonext(visited,cy+stepstohorizontalwall*curdir.F,cx+stepstohorizontalwall*curdir.S,getcorner[dir]);
        if(res == -1) return -1;
        return 1+res;
    }
    if(stepstohorizontalwall < stepstoverticalwall){
        int res = gotonext(visited,cy+stepstohorizontalwall*curdir.F,cx+stepstohorizontalwall*curdir.S,getnexthorizontal[dir]);
        if(res == -1) return -1;
        return 1+res;
    }
    else{
        int res = gotonext(visited,cy+stepstoverticalwall*curdir.F,cx+stepstoverticalwall*curdir.S,getnextvertical[dir]);
        if(res == -1) return -1;
        return 1+res;
    }
}

void solve(){
    string dir;
    cin >> n >> m;
    cin >> yy1 >> x1 >> y2 >> x2;
    cin >> dir;
    vector<vector<vector<int>>> visited(n+1,vector<vector<int>>(m+1,vector<int>(4,0)));
    cout << gotonext(visited,yy1,x1,mp[dir]) << "\n";
}
int main(){
    mp["DR"] = 0;
    mp["DL"] = 1;
    mp["UR"] = 2;
    mp["UL"] = 3;

    directions[0]= {1,1};
    directions[1] = {1,-1};
    directions[2] = {-1,1};
    directions[3] = {-1,-1};
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
