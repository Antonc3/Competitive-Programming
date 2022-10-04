#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005
#define f first
#define s second

int a[MAXN], b[MAXN], n;
int last[MAXN];
bool visited[MAXN];
int cameFrom[MAXN];
vector<int> ans;

void solve(){
    cin >> n;
    a[0] = 0, b[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    queue<int> q;
    q.push(n);
    fill(last, last+n+2, -1);
    fill(visited, visited+n+2, false);
    fill(cameFrom, cameFrom+n+2, -1);
    last[n] = n;
    cameFrom[n] = n;
    int last_traveled = n;
    while(!q.empty()){
        int cur = q.front();
        // cout << "came from: " << cameFrom[cur] << " last " << last[cur]<<endl;
        // cout <<"cur " << cur << " last_traveled "<< last_traveled << endl;
        q.pop();
        // if(visited[cur] != false) continue;
        while(last_traveled >= cur-a[cur]){     
            last[last_traveled] = cameFrom[cur];
            if(!visited[last_traveled+b[last_traveled]]){
                q.push(last_traveled+b[last_traveled]);
                cameFrom[last_traveled+b[last_traveled]] = last_traveled;
                visited[last_traveled+b[last_traveled]] = true;
            }
            last_traveled--;
        }   
        visited[cur] = true;
    }
    if(last_traveled != -1){
        cout << -1<<endl;
        return;
    }
    int cur = 0;
    // for(int i = 0; i <= n; i++){
    //     cout << last[i] << " " ;
    // }
    // cout << endl;
    // ans.push_back(0);
    while(cur != n){
        // cout << cur << "  last cur " << last[cur] << " n " << n << endl;
        ans.push_back(cur);
        cur = last[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size()<<endl;
    for(int i : ans){
        cout << i << " ";
    }
}

int main(){ 
    solve();
}