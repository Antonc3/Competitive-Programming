
#include <bits/stdc++.h>
using namespace std;

void dfs(int cur,vector<int> &arr, vector<int> &visited,vector<int> &ends){
    visited[cur] = 1;
    if((cur+arr[cur] <= 0 ) || (cur+arr[cur]) > arr.size()-1){
        ends[cur] = 1;
        return;
    }
    if(arr[cur] == 0){
        ends[cur] = 0;
        return;
    }
    if(!visited[cur+arr[cur]]){
        dfs(cur+arr[cur],arr,visited,ends);
    }
    ends[cur] = ends[cur+arr[cur]];
}

void getPath(int cur, vector<int> &arr, vector<int> &visited, vector<int> &path){
    path.push_back(cur);
    visited[cur] = 1;
    if(arr[cur] == 0 || (cur+arr[cur] <= 0 ) || (cur+arr[cur]) > arr.size()-1){
        return;
    }
    if(!visited[cur+arr[cur]]){
        getPath(cur+arr[cur],arr,visited,path);
    }
}

//what do we want to do
//calculate all of the number of indecies that end up on the starting path
//count the number of nodes that branch into the "main" pathway
void calcEntries(int cur, vector<int> &arr, vector<int> &path,vector<int> &visited, vector<int> &onPath){
    visited[cur] = 1;
    if((cur+arr[cur] <= 0 ) || (cur+arr[cur]) > arr.size()-1){
        return;
    }
    if(!visited[cur+arr[cur]]){
        calcEntries(cur+arr[cur],arr,path,visited,onPath); 
    }
    onPath[cur] = onPath[cur+arr[cur]];
    visited[onPath[cur]]++;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> ends(n+1,0);
    vector<int> visited(n+1,0);
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        dfs(i,arr,visited,ends);
    }
    int numEnds = 0;
    for(int i = 1; i <= n; i++){
        if(ends[i]) numEnds++;
    }
    vector<int> path;
    visited = vector<int>(n+1,0);
    getPath(1,arr,visited,path);
    long long ans = 0;
    vector<int> path2(n+1,0);
    vector<int> onPath(n+1,0);
    for(int i = 0; i < path.size();i++){
        path2[path[i]]=1;
        onPath[path[i]] = path[i];
    }
    for(int i = 1; i < n+1; i++){
        if(visited[i]>0) continue;
        calcEntries(i,arr,path2,visited,onPath);
        // cout << "ONPATH " << i << " is on " << onPath[i]<<endl;
    }
    long long toSub = 0;
    for(int cur : path){
        long long toAdd = n+1+numEnds;
        toSub+=visited[cur];
        // cout << visited[cur] << endl;
        if(ends[1]){
            toAdd-=toSub;
        }
        ans+=toAdd;
    }
    if(ends[1]){
        ans+=(1ll*n-1ll*path.size())*(2ll*n+1ll);
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

