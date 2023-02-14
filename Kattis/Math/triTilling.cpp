#include <bits/stdc++.h>
using namespace std;
#define MAXN 33

int dp[MAXN];

int main(){
  int n;
  for(int i = 0; i < MAXN; i++){
    if(i==0) dp[i] = 1;
    else{
      if(i%2==0){
        dp[i] = dp[i] + 3*dp[i-2];
        if(i>=4){
          int j = i-4;
          while(j>=0){
            dp[i] += dp[j] * 2;
            j-=2;
          }
        }
      }
      else{
        dp[i] = 0;
      }
    }
  }
  while(true){
    cin >> n;
    if(n==-1) return 0;
    cout << dp[n] << endl;
  }
}
