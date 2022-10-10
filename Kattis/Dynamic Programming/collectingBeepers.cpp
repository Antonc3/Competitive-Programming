#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define INF 1e9
typedef pair<int,int> pii;

pii start;
pii beepers[11];
int ans;
pii grid;
vector<int> notVisited;
int numBeepers;

int dist(pii a, pii b){
  return abs(a.f-b.f) + abs(a.s-b.s);
}

void dfs(int cur, int cDist){
  int nvSize = notVisited.size();
  if(cur==-1){
    for(int i = 0; i < nvSize; i++){
      int toSearch = *notVisited.begin();
      notVisited.erase(notVisited.begin());
      dfs(toSearch, dist(start,beepers[toSearch]));
      notVisited.push_back(toSearch);
    }
    return;
  }
  if(nvSize == 0){
    ans = min(ans,dist(beepers[cur],start)+cDist);
    return;
  }
  for(int i = 0; i < nvSize; i++){
    int toSearch = *notVisited.begin();
    notVisited.erase(notVisited.begin());
    dfs(toSearch,cDist+dist(beepers[cur],beepers[toSearch]));
    notVisited.push_back(toSearch);
  }
  return;
}
void solve(){
  notVisited.clear();
  cin >> grid.f >> grid.s;
  cin >> start.f >> start.s;
  cin >> numBeepers;

  for(int i = 0; i < numBeepers; i++){
    notVisited.push_back(i);
    cin >> beepers[i].f >> beepers[i].s;
  }
  ans = INF;
  dfs(-1, 0);
  cout << ans << endl;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
