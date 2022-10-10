#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

int n,m;
double prob[MAXN*2];
double dp[MAXN*2][MAXN];


int main(){
  cin >> n >> m;
  for(int i = 1; i <= n+m-1; i++){
    cin >> prob[i];
  }
  for(int i = 0; i <= n+m-1; i++){
    for(int j = n; j >= 0; j--){
      if(i == 0){
        dp[i][j] = 0;
        if(j==n){
          dp[i][j] = 1;
        }
        continue;
      }
      if(j==n){
        dp[i][j] = dp[i-1][j]*prob[i];
        continue;
      }
      dp[i][j] = dp[i-1][j+1]*(1.0-prob[i]) + dp[i-1][j]*prob[i];
      if(j==0){
        dp[i][j] += dp[i-1][j]*(1.0-prob[i]);
      }
    }
  }
  cout <<setprecision(10)<< (1.0-dp[n+m-1][0])<<endl;
}
