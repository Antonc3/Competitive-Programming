#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 100005

int n, p;
int listen[MAXN];
void solve(){
  cin >> n >> p;
  for(int i = 0; i < n; i++){
    cin >> listen[i];
    listen[i]-=p;
  }
  ll ans = 0;
  ll cur = 0;
  for(int i = 0; i < n; i++){
    if(listen[i] > 0){
      cur+=listen[i];
      ans = max(ans, cur);
    }
    else{
      cur = max(0ll,cur+listen[i]);
    }
  }
  cout << ans;
}

int main() {
  solve();
}
