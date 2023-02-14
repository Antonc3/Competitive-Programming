#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int votes[26][26];

bool works[30];
bool visited[30];
vector<int> losesTo;
bool dfs(vector<int> adj[], int cur, int cnt){
  bool ans = false;
  for(int i : adj[cur]){
    if(works[i] && cnt == losesTo.size()) return true;
    else if(works[i]) continue;
    if(visited[i]) continue;
    visited[i] = true;
    ans |=dfs(adj, i, cnt+1);
    visited[i]= false;
  }
  return ans;
}
/*
bool check(int tocheck){
  losesTo.clear();
  fill(works, works+n, false);
  for(int i = 0; i < n; i++){
    if(votes[tocheck][i] < 0){
      losesTo.push_back(i);
    }
    else{
      works[i] = true;
    }
  }
  vector<int> adj[30];
  for(int i : losesTo){
    for(int j = 0; j < n; j++){
      if(votes[i][j] < 0){
        adj[i].push_back(j);
      }
    }
  }
  for(int i : losesTo){
    fill(visited, visited+n+1, false);
    if(dfs(adj,i, 1)) return true;
  }
  return false;
}
*/

bool check(int tocheck){
  bool canbeat[30];
  fill(canbeat, canbeat+n+1, false);
  int cnt = 1;
  canbeat[tocheck] = true;
  stack<int> tochecks;
  tochecks.push(tocheck);
  while(!tochecks.empty()){
    if(cnt==n) break;
    int cur = tochecks.top();
    tochecks.pop();
    for(int i = 0; i < n; i++){
      if(canbeat[i]) continue;
      if(votes[cur][i] >= 0) {
        canbeat[i] = true;
        cnt++;
        tochecks.push(i);
      }
    }
  }
  return cnt ==n;
}

void solve(){
 cin >> n >> m;
 for(int i = 0; i < m; i++){
   int nvotes;
   string s;
   cin >> nvotes >> s;
   for(int j = 0; j < n; j++){
     int cur = s[j]-'A';
     for(int k = j+1; k < n; k++){
      int nxt = s[k]-'A';
      votes[cur][nxt] += nvotes; 
      votes[nxt][cur] -= nvotes;
     }
   }
 }
 for(int i = 0; i < n; i++){
   bool works = check(i);
   cout << (char)(i + 'A') << (works ? ": can win" : ": can't win")<<endl;
 }
}

int main() {
  solve();
}
