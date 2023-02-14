#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int ft[MAXN];

void update(int x, int v){
  for(; x < MAXN; x+=(x&-x)){
    ft[x]+=v;
  }
}
int query(int x){
  int sum = 0;
  for(; x > 0; x-=(x&-x)){
    sum+=ft[x];
  }
  return sum;
}

int n,r;
int movie[MAXN];

void solve(){
  fill(ft, ft+sizeof(ft)/sizeof(ft[0]),0);
  fill(movie, movie+sizeof(movie)/sizeof(movie[0]),0);
  cin >> n >> r;
  for(int i = 1; i <= n; i++){
    update(i,1);
    movie[i] = n-i+1;
  }
  int count = n+1;
  for(int i = 0; i < r; i++){
    int a;
    cin >> a;
    cout << n-query(movie[a]) << " ";
    update(movie[a],-1);
    movie[a] = count++;
    update(movie[a],1);
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
