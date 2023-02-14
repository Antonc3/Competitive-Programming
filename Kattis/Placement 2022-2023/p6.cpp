#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<string,int> um;
bool compStr(string s, string x){
  return s.length() > x.length();
}

bool origOrder(string s, string x){
  return um[s] < um[x];
}
int n;
vector<string> v;
void solve(){
 cin >> n; 
 for(int i = 0; i < n; i++){
   string s;
   cin >> s;
   v.push_back(s);
   um.insert({s,i});
 }
 sort(v.begin(), v.end(), compStr);
 int ni = 1;
 //sorted from high to lwo
 vector<string> ans;
 vector<int> lenStart;
 for(int i = 0; i < n; i++){
  while(v[ni].length() == v[i].length()) ni++;
  lenStart.push_back(ni);
  i = ni-1;
 }
 lenStart.push_back(n);
 int lsi = 0;
 for(int i = 0; i < n; i++){
   string cur = v[i];
   if(i >= lenStart[lsi]) lsi++;
   if(lsi >= lenStart.size()){
     break;
   }
   int curSize = cur.length();
   int lsSize = v[lenStart[lsi]].length();
   if(curSize != lsSize+1) continue;
   //only start comparison if sizes are 1 apart
   bool isMispelled = false;
   for(int j = lenStart[lsi]; j < lenStart[lsi+1]; j++){
    int jj = 0;
    string toComp = v[j];
    isMispelled = true;
    for(int ii = 0; ii < cur.length(); ii++){
      if(toComp[jj] != cur[ii]) ii++; 
      if(ii-jj>1){
        isMispelled = false;
        break;
      }
      jj++;
    }
    if(isMispelled) {
      ans.push_back(cur);
      break;
    }
   }
 }
 sort(ans.begin(), ans.end(), origOrder);
 if(ans.size() == 0){
   cout << "NO TYPOS\n";
 }
 for(string s : ans){
   cout << s <<endl;
 }
 
}

int main() {
  solve();
}
