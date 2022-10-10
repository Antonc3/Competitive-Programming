#include <bits/stdc++.h>
using namespace std;
#define MAXN 205

string s;
int n;
//dp[i] represents the maximal factoring of 0...i
//dp[i][j] represnets the maximal factoring of i ... j
//transition from one state to the next is
//dp[i][j] = 
int dp[MAXN];

int main(){
  cin >> s;
  n = s.length();
  dp[0] = 0;
  for(int i = 1; i <= n; i++){
    if(i==1){
      dp[i] = 1;
    } 
  }
  
}
