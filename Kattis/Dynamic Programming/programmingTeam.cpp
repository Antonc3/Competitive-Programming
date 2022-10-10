#include <bits/stdc++.h>
using namespace std;
#define MAXN 2505
#define f first
#define s second
typedef pair<int,int> pii;

int sal[MAXN];
int prod[MAXN];
int rec[MAXN];
//dp[i][j] records 
pii dp[MAXN][MAXN];
int k, n;


int main(){
  cin >> k >> n;
  for(int i = 1; i <= n; i++){
    cin >> sal[i] >> prod[i] >> rec[i];
  }

}
