#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int lps[MAXN];

bool solve(){
  string pat, txt;
  getline(cin, pat);
  int n = pat.length();
  if(n == 0) return false;
  lps[0] = 0;
  int i = 1;
  int len = 0;
  while(i < n){
    if(pat[i] == pat[len]){
      lps[i] = ++len;
      i++;
    }
    else{
      if(len == 0){
        lps[i] = 0;
        i++;
      }
      else{
        len = lps[len-1];
      }
    }
  }
  i = 0;
  int j =0;
  vector<int> ans;
  getline(cin, txt);
  int m = txt.length();
  while((m-i) >= (n-j)){
    if(pat[j] == txt[i]){
      i++;
      j++;
    }
    if(j==n){
      cout << i-n<< " ";
      j = lps[n-1];
    }
    else if(i < m && pat[j] != txt[i]){
      if(j!=0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
  }
  cout << endl;
  return true;
}

int main(){
  while(!cin.eof()){
    solve();
  }
}
