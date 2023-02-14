#include <bits/stdc++.h>
using namespace std;
#define MAXN 205
#define INF 2e9
typedef long long ll;
int rows[MAXN], cols[MAXN];
int b[MAXN][MAXN];
int a[MAXN][MAXN]; 
int n,m;

void readInput(int x, int y, char sign, int v){
  if(sign == '>'){
    a[x][y] = max(a[x][y],v+1);
  }
  else if(sign == '<'){
    b[x][y] = min(b[x][y], v-1);
  }
  else{
    b[x][y] = min(b[x][y], v);
    a[x][y] = max(a[x][y],v);
  }
}

//build network flow

vector<vector<int>> adj;
int flow[4500][4500];
int cap[4500][4500];
void buildNetwork(){
  fill(&flow[0][0],&flow[0][0]+sizeof(flow)/sizeof(flow[0][0]),0);
  fill(&cap[0][0],&cap[0][0]+sizeof(cap)/sizeof(cap[0][0]),0);
  adj = vector<vector<int>>(4500);
  for(int i = 0; i < m; i++){
    int rowCap = rows[i];
    for(int j = 0; j < n; j++){
      rowCap -= a[i][j];
    }
    cap[0][n*m+1+i] = rowCap;
    adj[0].push_back(n*m+1+i);
    adj[n*m+1+i].push_back(0);
  } 
  for(int i = 0; i < n; i++){
    int colCap = cols[i];
    for(int j = 0; j < m; j++){
      colCap-= a[j][i];
    }
    cap[n*m+1+m+i][4499] = colCap;
    adj[n*m+1+m+i].push_back(4499);
    adj[4499].push_back(n*m+1+m+i);
  } 
  for(int i = 0; i < m; i++){
    for(int j =0; j < n; j++){
      cap[n*m+1+i][1+i*n+j] = b[i][j]-a[i][j];
      cap[1+i*n+j][n*m+1+m+j] = b[i][j]-a[i][j];
      adj[n*m+1+i].push_back(1+i*n+j);
      adj[1+i*n+j].push_back(n*m+1+i);
      adj[1+i*n+j].push_back(n*m+1+m+j);
      adj[n*m+1+m+j].push_back(1+i*n+j);
    }
  }
}

bool bfs(vector<int> &v){
  v = vector<int>(4500,4500);
  queue<int> q;
  q.push(0); 
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : adj[cur]){
      if(cap[cur][i]-flow[cur][i] > 0 && v[i] == 4500){
        q.push(i);
        v[i] = cur;
        if(i == 4499) return true;
      }
    }
  }
  return false;
}

int augment(vector<int> &v){
  int cur = 4499;
  int aug  = INF;
  while(cur != 0){
    aug = min(aug,cap[v[cur]][cur]-flow[v[cur]][cur]);
    cur = v[cur];
  }
  cur = 4499;
  while(cur!=0){
    flow[v[cur]][cur]+=aug;
    flow[cur][v[cur]]-=aug;
    cur = v[cur];
  }
  return aug;
}

int edmundKarp(){
  buildNetwork();
  vector<int> v;
  int flowPushed = 0;
  while(bfs(v)){
    flowPushed+= augment(v);
  }
  return flowPushed;
}

void solve(){
  cin >> m >> n;
  int rSum = 0, cSum  =0;
  fill(&b[0][0], &b[0][0]+sizeof(b)/sizeof(b[0][0]), INF);
  fill(&a[0][0], &a[0][0]+sizeof(a)/sizeof(a[0][0]), 0);
  for(int i = 0; i < m; i++){
    cin >> rows[i];
    rSum+=rows[i];
  }
  for(int i = 0; i < n; i++){
    cin >> cols[i];
    cSum+=cols[i];
  }
  int k;
  cin >> k;
  for(int i = 0; i < k; i++){
    int r,c,v;
    char oper;
    cin >> r >> c >> oper >> v;
    r--; c--;
    if(r==-1){
      for(int rr = 0; rr < m; rr++){
        if(c==-1){
          for(int cc = 0; cc < n; cc++){
            readInput(rr,cc,oper,v);
          }
        }
        else{
          readInput(rr,c,oper,v);
        }
      }
    }
    else if(c==-1){
      for(int cc = 0; cc < n; cc++){
        readInput(r,cc,oper,v);
      }
    }
    else{
      readInput(r,c,oper,v);
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(a[i][j] > b[i][j]){
        cout << "IMPOSSIBLE\n\n";
        return;
      }
    }
  }
  if(rSum != cSum){
    cout << "IMPOSSIBLE"<<endl<<endl;
    return;
  }
  int toAdd = 0;
  for(int i = 0; i < m; i++){
    for(int j =0; j < n; j++){
      toAdd+=a[i][j];
    }
  }
  if(edmundKarp()+toAdd != rSum){
    cout << "IMPOSSIBLE"<< endl<< endl;
    return;
  }
  for(int i = 1; i < n*m+1; i++){
    int x = (i-1)%n;
    int y = (i-x-1)/n;
    cout << a[y][x] + flow[i][n*m+m+x+1]<< " ";  
    if(i!= 1 && x==n-1)
      cout << endl;
  }
 cout << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
