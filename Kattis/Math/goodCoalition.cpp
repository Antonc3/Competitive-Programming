#include <bits/stdc++.h>

using namespace std;
#define MAXN 155

double dp[MAXN][MAXN];
int n;
double prob[MAXN], popul[MAXN];

void solve(){
  fill(&dp[0][0], &dp[0][0] + sizeof(dp)/sizeof(dp[0][0]),0.0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> popul[i] >> prob[i];
  }

  for(int i = 0; i <= n; i++){
    //the current group we are onj
    for(int j = 0; j < MAXN; j++){
      if(j==0){
        dp[i][j] = 100.0;
        continue;
      }
      if(i==0){
        dp[i][j] = 0.0;
        continue;
      }
      int curPop= popul[i]; 
      if(j-curPop < 0){
        dp[i][j] = dp[i-1][j];
        continue;
      }
      dp[i][j] = max(dp[i-1][j-curPop]*prob[i]/100.0,dp[i-1][j]);
    }
  }
  double ans = 0.0;
  for(int i = 76; i < MAXN; i++){
    ans = max(ans, dp[n][i]);
  }
  cout << setprecision(11) << ans << endl;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}

