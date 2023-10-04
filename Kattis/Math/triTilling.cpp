#include <bits/stdc++.h>
using namespace std;
#define MAXN 33

int dp[MAXN];

int main(){
  int n;
  dp[0] = 1;
  for(int i = 0; i < MAXN; i++){
    dp[i+2]=dp[i+2]+dp[i]*3;
    for(int j = i+4; j < MAXN; j+=2){
       dp[j] = dp[j] + dp[i]*2; 
    }
  }
  while(true){
    cin >> n;
    if(n==-1) return 0;
    else cout << dp[n] << endl;
  }
}
