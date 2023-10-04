#include <bits/stdc++.h>
using namespace std;

int dfs(int cur, vector<int> &arr,vector<int> & visited, vector<int> & num){
    int nxt = arr[cur];
    if(visited[nxt] == visited[cur]){
        return num[cur]-num[nxt]+1;
    }
    else if(visited[nxt] == -1){
        visited[nxt] = visited[cur];
        num[nxt] = num[cur]+1;
        return dfs(nxt,arr,visited,num);
    }
    return -1;

}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i =1;i <= n; i++) cin >> arr[i];
    vector<int> visited(n+1,-1), num(n+1,0);
    int same = 0;
    for(int i = 1; i <= n; i++){
        if(arr[i] == i) same++;
    }
    if(k==1){
        if(same == n){
            cout << "YES\n";
        }
        else{
            cout <<"NO\n";
        }
        return;
    }
    if(same){
        cout << "NO\n";
        return;
    }
    int cntr =0 ;
    for(int i = 1; i <= n; i++){
        if(visited[i] != -1){
            continue;
        }
        visited[i] = cntr++;
        int len = dfs(i,arr,visited,num);
        if(len == -1) continue;
        if(len != k){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}