#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

int MOD = pow(2,31)-1;
int n;
int grid[MAXN][MAXN];
long long dp[MAXN][MAXN];

bool visited[MAXN][MAXN];
bool dfs(int x, int y){
  if(x == n-1 && y ==n-1){
    return true;
  }
  int mX[4] = {0, -1, 0, 1};
  int mY[4] = {1, 0, -1, 0};

  bool ans = false;
  for(int i = 0; i < 4; i++){
    int nX = x + mX[i];
    int nY = y + mY[i];
    if(nX < 0 || nY < 0 || nX >= n || nY >= n) continue;
    if(grid[nX][nY] == 0) continue;
    if(visited[nX][nY]) continue;
    visited[nX][nY] = true;
    ans = ans || dfs(nX,nY);
  }
  return ans;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < n; j++){
      if(s[j] == '.'){
        if(i==0 && j==0){
          dp[i][j] = 1;
        }
        grid[i][j] = 1;
        if(j != 0 && grid[i][j-1] == 1){
          dp[i][j]+=dp[i][j-1];
          dp[i][j]%=MOD;
        }
        if(i != 0 && grid[i-1][j] == 1){
          dp[i][j]+=dp[i-1][j];
          dp[i][j]%=MOD;
        }
      }
      else{
        grid[i][j] = 0;
        dp[i][j] = 0;
      }
      // cout << dp[i][j] << " ";
    }
    // cout << endl;
  }
        
  if(dp[n-1][n-1]==0){
    fill(&visited[0][0], &visited[0][0]+sizeof(visited)/sizeof(visited[0][0]), false);
    if(!dfs(0,0)){
      cout << "INCONCEIVABLE\n";
    }
    else{
      cout << "THE GAME IS A LIE\n";
    }
  }
  else{
    cout << dp[n-1][n-1]<<endl;
  }
}
