#include <bits/stdc++.h>

using namespace std;
#define MAXN 7005

int n;
int f[MAXN][MAXN];
int c[MAXN][MAXN];
vector<int> adj[MAXN];
char inp[MAXN][MAXN];
const bool DEBUG = false;

bool bfs(vector<int> &v){
  v= vector<int>(MAXN,MAXN);
  v[0] = -1;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i : adj[cur]){
      if(c[cur][i]-f[cur][i] > 0 && v[i] == MAXN){
        q.push(i);
        v[i] = cur;
        if(i == n*n){
          return true;
        }
      }
    }
  }
  if(DEBUG) cout <<"v[n*n]" << v[n*n]<<endl;
  return v[n*n] !=MAXN;
}

int augment(vector<int> &v){
  int minflow = MAXN;
  for(int i = n*n; v[i] != -1; i = v[i]){
    minflow = min(minflow, c[v[i]][i]-f[v[i]][i]);
  }
  for(int i = n*n; v[i] != -1; i = v[i]){
    f[v[i]][i] += minflow;
    f[i][v[i]] -= minflow;
  }
  return minflow;
}

int edmundKarp(){
  vector<int> v;
  int flow = 0;
  while(bfs(v)){
    if(DEBUG) cout << flow << endl;
    flow+=augment(v);
  }
  return flow;
}

void solve(){
  cin >> n;
  fill(&f[0][0], &f[0][0]+sizeof(f)/sizeof(f[0][0]),0);
  fill(&c[0][0], &c[0][0]+sizeof(c)/sizeof(c[0][0]),0);

  for(int i = 0; i < n*2-1; i++){
    for(int j = 0; j < n*2-1; j++){
      cin >> inp[i][j];
    } 
  }
  int dir[] = {-1,0,1,0};
  for(int i = 1; i < n*2-1; i+=2){
    for(int j = 1; j < n*2-1; j+=2){
      int x = (j-1)/2;
      int y = (i-1)/2;
      int tot = 0;
      int outside = 0;
      for(int d = 0; d < 4; d++){
        int dx = dir[d];
        int dy = dir[(d+1)%4];
        if(DEBUG) cout << "dx,dy" << dx << ", " << dy<<endl;
        if(inp[i+dy][j+dx]=='.'){
          tot++;
          if(!(x==0&&dx==-1) && !(x==n-2 && dx==1) && !(y==0&&dy==-1) && !(y==n-2&&dy==1)){
            if((x+y)%2==0){
              c[1+y*n+x][1+(y+dy)*n+x+dx]=1; 
              if(DEBUG) cout << "x, y " << x << ", " << y << " dx,dy " << x+dx << ", " <<y+dy<<endl;
              adj[1+y*n+x].push_back(1+(y+dy)*n+x+dx);
              adj[1+(y+dy)*n+x+dx].push_back(1+y*n+x);
            }
          }
          else{
            outside++;
          }
        }
      }
      if(DEBUG) cout << "x,y: " << x << ", " << y << " tot: " << tot << " outside " << outside << endl;
      if((x+y)%2==0){
        c[0][1+y*n+x] = tot-1;
        c[1+y*n+x][n*n] = outside;
        if(tot-1>0) adj[0].push_back(1+y*n+x);
        if(outside > 0) adj[1+y*n+x].push_back(n*n);
      }
      else{
        c[0][1+y*n+x] = outside;
        c[1+y*n+x][n*n] = tot-1;
        if(outside>0) adj[0].push_back(1+y*n+x);
        if(tot-1 > 0) adj[1+y*n+x].push_back(n*n);
      }
    }
  }
  if(DEBUG){
    for(int i = 0; i<= n*n; i++){
      for(int j =0; j <=n*n; j++){
        cout << c[i][j]<< " ";
      }
      cout << endl;
    }
  }
  cout << 1+edmundKarp()<<endl;
}

int main(){
  solve();
}
