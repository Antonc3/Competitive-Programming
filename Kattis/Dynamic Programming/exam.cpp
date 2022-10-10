#include <bits/stdc++.h>

using namespace std;

int main(){
  int k;
  cin >> k;
  string yAns, fAns;
  cin >> yAns>>fAns;
  int n = yAns.length();
  int ans = 0;
  int kCnt = 0;
  for(int i = 0; i < n; i++){
    if(yAns[i] == fAns[i]){
      if(kCnt < k){
        kCnt++;
        ans++;
      }
    }
    else{
      if(i-kCnt < n-k){
        ans++;
      }
    }
  }
  cout << ans << endl;
}
