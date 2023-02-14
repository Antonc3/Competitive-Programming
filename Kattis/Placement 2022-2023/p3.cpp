#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 200005
#define F first
#define S second

int n, m, s;
vector<pair<pii,pii>> adj[MAXN];
int visited[MAXN];

int dijk(){
  priority_queue<pii> pq;
  pq.push({s,n-1});
  while(!pq.empty()){
    pii cur = pq.top();
    pq.pop();
    if(cur.F <= visited[cur.S] && visited[cur.S] != -1){
      continue;
    }
    visited[cur.S] = cur.F;
    if(cur.S == 0) break;
    for(auto edge : adj[cur.S]){
      //latest arrival that gets to current node by time -cur.F is
      int k = ((cur.F) - edge.S.S-edge.F.S)/edge.S.F;
      if(k < 0) continue;
      int earliestDep = edge.F.S + edge.S.F*k;
      if(visited[edge.F.F] == -1 || visited[edge.F.F] < earliestDep){
        pq.push({earliestDep, edge.F.F});
      }
    }
  }
  return visited[0];
}

void solve(){
  cin >> n >> m >> s;
  fill(visited, visited+n+1, -1);
  for(int i = 0; i < m; i++){
    int u, v, t, p, d;
    cin >> u >> v >> t >> p >> d;
    adj[v].push_back({{u, t}, {p, d}});
  }
  int earliestTime =  dijk();
  if(earliestTime < 0){
    cout << "impossible\n";
  } 
  else{
    cout << earliestTime<<endl;
  }
}

int main() {
  solve();
}
