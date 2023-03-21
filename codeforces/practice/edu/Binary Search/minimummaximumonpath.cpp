#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct edge{
    int to, num;
};
int n,m,d;
vector<edge> adj[MAXN];

vector<int> last;
bool check(int val){
    //cout << "checking: " << val << endl;
    vector<int> visited(n+1,-1);
    last = vector<int>(n+1,0);
    queue<int> q;
    q.push(1);
    last[1] = -1;
    visited[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        //cout << "cur: " << cur << endl;
        if(visited[cur] > d) return false;
        if(cur == n) return true;
        for(edge x : adj[cur]){
            if(visited[x.to] != -1) continue;
            if(x.num > val) continue;
            visited[x.to] = visited[cur] + 1;
            last[x.to] = cur;
            q.push(x.to);
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> d;

    for(int i = 0;i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    if(!check(1e9)){
        cout << -1<<endl;
        return 0;
    }
    int l = 0, r = 1e9;
    int best = r;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    check(best);
    vector<int> path;
    for(int i = n; i != -1; i = last[i]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    cout << path.size()-1<<"\n";
    for(int i : path) cout << i << " ";
}
