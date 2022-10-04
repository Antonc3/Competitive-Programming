#include <bits/stdc++.h>

using namespace std;
#define MAXN 400005
#define f first
#define s second
typedef pair<int,int> pii;
int n;
// int meetings[MAXN];

vector<pii> meetings;
int meetingLength[MAXN];
vector<int> adj[MAXN];

bool visited[MAXN];
int meetingCount = 0;
int ans =0;
void dfs(int cur){
    // cout << "CURRENTLY SEARCHING: " << cur<<endl;
    for(int i : adj[cur]){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
    }
    // cout << "DONE WITH: " << cur<<endl;
    ans = max(ans,meetingLength[cur]+meetingCount);
    meetingCount++;
}

int main(){
    cin >> n;
    fill(visited, visited+n,false);
    // priority_queue<pii> pq;
    for(int i = 1; i <= n; i++){
        int e,d;
        cin >> e >> d;
        // if(d == 0) pq.push({e,i});
        for(int j = 0; j < d; j++){
            int a;
            cin >> a;
            adj[i].push_back(a);
        }
        meetingLength[i] = e;
        // meetings[i] = d;
        meetings.push_back({e,i});
    }
    sort(meetings.begin(), meetings.end(), greater<pii>());
    // cout << "HERE"</<endl;
    for(int i = 0; i < meetings.size(); i++){
        pii cur = meetings[i];
        // cout << "ON MEETIN.G: " << cur.s << endl;
        if(visited[cur.s]) continue;
        visited[cur.s] = true;
        dfs(cur.s);
    }
    // int meetingCount = 0;
    // while(!pq.empty()){
    //     pii cur = pq.top();
    //     // cout << "ON MEETING: " << cur.s<<endl;
    //     pq.pop();
    //     ans = max(cur.f+meetingCount, ans);
    //     meetingCount++;
    //     for(int i : adj[cur.s]){
    //         meetings[i]--;
    //         if(meetings[i] == 0) pq.push({meetingLength[i],i});
    //     }
    // }
    cout << ans;
}