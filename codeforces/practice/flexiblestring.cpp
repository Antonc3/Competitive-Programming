#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,k;
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    
    map<char,int> mp;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mp.count(a[i]) == 0){
            mp[a[i]] = cnt;
            cnt++;
        }
    }
    k = min(k,cnt);
    ll best = 0;
    for(int i = 0; i <= (1<<cnt); i++){
        int nk = 0;
        for(int j = 0; j <= (cnt); j++){
            if(i&(1<<j)) nk++;
        }
        if(nk != k) continue;
        //check ur mother
        
        int last = 0;
        int cur = 0;
        ll curans = 0;
        while(cur < n){
            char curchar = a[cur];
            int curind = mp[curchar];
            if((1<<curind) & i || a[cur] == b[cur]) cur++;
            else{
                curans += (1ll*(cur-last)*(cur-last+1)/2);
                cur++;
                last = cur;
            }
        }
        curans+=(1ll*(cur-last)*(cur-last+1)/2);
        best = max(best,curans);
    }
    cout << best << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
