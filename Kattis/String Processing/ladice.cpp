#include <bits/stdc++.h>

using namespace std;
#define MAXN 300005

int dsu[MAXN];
int dsize[MAXN];
int get(int x){
  return (dsu[x] < 0) ? x : dsu[x] = get(dsu[x]);
}
void join(int x, int y){
  x = get(x);
  y = get(y);
  if(x==y) return;
  if(dsu[x] > dsu[y]) swap(x,y);
  dsu[x] += dsu[y];
  dsize[x] += dsize[y];
  dsu[y] = x;
}
int n, l;

int main(){
  cin >> n >> l;
  for(int i = 0; i <= l+1; i++){
    dsu[i] = -1;
    dsize[i] = 0;
  }
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    join(a,b);
    int root = get(a);
    if(-dsu[root] <= dsize[root]){ 
      cout << "SMECE\n"; 
    }
    else{
      dsize[root]++;
      cout << "LADICA\n";
    }
  }
}
