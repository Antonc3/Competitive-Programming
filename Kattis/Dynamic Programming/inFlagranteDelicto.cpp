#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define f first
#define s second
typedef pair<int,int> pii;

int pros[MAXN], pI[MAXN];

int def[MAXN], dI[MAXN];
//
//the longest common subsequence from i ... n
//is stored in dp[i]
set<pii> st;
int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> pros[i];
    pI[pros[i]] = i;
  }

  for(int i = 1; i <= n; i++){
    cin >> def[i];
    dI[def[i]] = i;
  }
  st.insert({0,0});
  int longestSub = 0;
  for(int i = 1; i <= n; i++){
    int cur = pros[i];
    int dIcur = dI[cur];
    auto it = st.lower_bound({dIcur,0});
    if(it == st.end()){
      st.insert({dIcur,++longestSub});
      continue;
    }
    int len = it->s;
    st.erase(it);
    st.insert({dIcur,len});
  }
  cout << "2 " << longestSub+1<<endl;
}
