#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int ft[7][MAXN];

void update(int i, int x, int val){
  for(; x < MAXN; x+=(x&-x)){
    ft[i][x]+= val;
  }
}

int query(int i, int x){
  int sum = 0;
  for(; x > 0; x-=(x&-x)){
    sum+=ft[i][x];
  }
  return sum;
}

int n, q;
int value[7];
int curType[MAXN];
int main(){
  fill(&ft[0][0], &ft[0][0]+sizeof(ft)/sizeof(ft[0][0]),0);
  cin >> n >> q;
  for(int i =1; i < 7; i++){
    cin >> value[i];
  }
  string s;
  cin >> s;
  for(int i = 1;i <= n; i++){
    int a= s[i-1]-'0';
    update(a,i,1);
    curType[i] = a;
  }
  for(int i = 0; i < q; i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(a == 1){
      update(curType[b], b, -1);
      update(c, b, 1);
      curType[b] = c;
    } 
    if(a==2){
      value[b] = c;
    }
    if(a==3){
      long long ans=0;
      for(int i = 1; i < 7; i++){
        long long cSum = 0;
        cSum =query(i,c)-query(i,b-1);
        cSum*=value[i];
        ans+=cSum;
      }
      cout << ans << endl;
    }
  }
}

