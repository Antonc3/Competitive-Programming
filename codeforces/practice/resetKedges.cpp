#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
#define f first
#define s second
typedef pair<int,int> pii;

int n, k;
int parent[MAXN];
vector<int> adj[MAXN];
vector<pii> depths;
int d[MAXN];
bool visited[MAXN];

void dfsDepth(int cur,int dpth){
  depths.push_back({dpth,cur});
  d[cur] = dpth;
  for(int i : adj[cur]){
    dfsDepth(i,dpth+1); 
  }
}

bool calcPossible(int depth){
  fill(visited, visited+n+2, false);
  //dfsDepth(1,0);
  int possible = 0;
  for(pii cur : depths){
    int cNode = cur.s;
    int cntr = 0; 
    if(cur.f <= depth) continue;
    possible++;
    while(cntr < depth){
      if(visited[cNode]){
        possible--;
        break;
      }
      if(d[cNode]==1){
        possible--;
        visited[cNode] = true; 
        break;
      }
      visited[cNode] = true;
      cNode = parent[cNode];
      cntr++;
    }
  }
  //cout << "depth: " << depth << " required moves: " << possible << endl;
  //
  return possible <= k;
}

void solve(){
  cin >> n >> k;
  depths.clear();
  parent[1] = 0;
  adj[1].clear();
  for(int i = 2; i <= n; i++){
    adj[i].clear();
    cin >> parent[i];
    adj[parent[i]].push_back(i);
  }
  dfsDepth(1,0); 
  sort(depths.begin(), depths.end(), greater<pii>());
  int l = 1, r = n+1;
  int best = MAXN;
  while( l <= r ){
    int mid = (l+r)/2;
    if(calcPossible(mid)){
      r = mid-1;
      best = mid;
    }
    else{
      l = mid+1;
    }
  }
  cout << best << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
