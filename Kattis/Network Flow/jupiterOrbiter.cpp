#include <bits/stdc++.h>

using namespace std;
#define MAXN 8000
#define INF 2e9

const bool DEBUG = false;

int n,q,s;
int f[MAXN][MAXN],c[MAXN][MAXN];
vector<int> adj[MAXN];
int sensors[MAXN];
int queues[MAXN];

void buildWindow(int winNum,vector<int> &window){
  //source at 0, sink at MAXN-1
  // (winNum)*(q+1) + 1 is start of the thing  
  //
  for(int i = 1; i < window.size(); i++){
    c[0][(winNum)*(q+1)*2+sensors[i-1]] += window[i];
  }
  for(int i = 0; i < q; i++){
    adj[0].push_back((winNum)*(q+1)*2+i+1);
  }
  int dataOutNode = (winNum+1)*2*(q+1);
  for(int i = 0; i < q; i++){
    int queueNode1 = (winNum)*(q+1)*2+sensors[i];
    int queueNode2 = (winNum)*2*(q+1)+q+1+sensors[i];
    int queueNode1OneOver = (winNum+1)*(q+1)*2+sensors[i];
    c[queueNode1][queueNode2] = queues[i];
    c[queueNode2][dataOutNode] = INF;
    c[queueNode2][queueNode1OneOver] = INF;
    adj[queueNode1].push_back(queueNode2);
    adj[queueNode2].push_back(queueNode1);
    adj[queueNode2].push_back(dataOutNode);
    adj[dataOutNode].push_back(queueNode2);
    adj[queueNode2].push_back(queueNode1OneOver);
    adj[queueNode1OneOver].push_back(queueNode2);
  }
  c[dataOutNode][MAXN-1] = window[0];
  adj[dataOutNode].push_back(MAXN-1);
}

bool bfs(vector<int> &v){
  queue<int> q;
  v = vector<int>(MAXN,MAXN);
  q.push(0);
  v[0] = -1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int a : adj[cur]){
      if(c[cur][a]-f[cur][a] > 0 && v[a] == MAXN){
        v[a] = cur;
        q.push(a);
      }
    }
  }
  return v[MAXN-1] != MAXN;
}

int augment(vector<int> &v){
  int aug = INF;
  for(int i = MAXN-1; v[i] != -1; i=v[i]){
    aug = min(aug,c[v[i]][i]-f[v[i]][i]);
  }
  if(DEBUG) cout << "Path: ";
  for(int i = MAXN-1; v[i] != -1; i=v[i]){
    if(DEBUG)cout << i << " ";
    f[v[i]][i]+=aug;
    f[i][v[i]]-=aug;
  }
  if(DEBUG) cout << " 0\n";
  return aug;
}

int edmundKarp(){
  vector<int> v;
  int flow = 0;
  while(bfs(v)){
    if(DEBUG) cout << "flow: " << flow << endl;
    flow+=augment(v);
  }
  return flow;
}

void solve(){
  fill(&f[0][0],&f[0][0]+sizeof(f)/sizeof(f[0][0]),0);
  fill(&c[0][0],&c[0][0]+sizeof(c)/sizeof(c[0][0]),0);
  cin >> n >> q >> s;
  for(int i =0; i < s; i++){
    cin >> sensors[i];
  }
  for(int i = 0; i < q; i++){
    cin >> queues[i];
  }
  long long expFlow = 0;
  for(int i = 0; i < n; i++){
    vector<int> window = vector<int>(s+2,0);
    cin >> window[0];
    for(int j = 1; j <=s; j++){
      cin >> window[j];
      if(DEBUG) cout << window[j] << " ";
      expFlow+=window[j];
    } 
    if(DEBUG) cout << endl;
    buildWindow(i,window);
  }
  if(DEBUG){
    for(int i = 0; i < 20; i++){
      for(int j = 0; j < 20; j++){
        cout << c[i][j] << " ";
      }
      cout << c[i][MAXN-1]<<endl;
    }
  }
  int flow = edmundKarp();
  if(DEBUG) cout << "expFlow: " << expFlow << " flow: " << flow << endl;
  
  if(flow != expFlow){
    cout << "impossible\n";
  }
  else{
    cout << "possible\n";
  }
  
}

int main(){
  solve();

}
