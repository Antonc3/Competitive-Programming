#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,p,k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    string ss = "1" + s;
    int x,y;
    cin >> x >> y;
    vector<int> cnt(n+2,0);
    for(int i = n; i >= 0; i--){
        cnt[i] = cnt[min(n+1,i+k)]+((ss[i]=='0') ? 1 : 0);
    }
    int best = 2e9;
    for(int i = 0; i <= n-p; i++){
        //cout << cnt[i] << " ";
        int cur = cnt[min(n+1,i+p)]*x+i*y; 
        best = min(best,cur);
    }
    //cout << endl;
    cout << best << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
