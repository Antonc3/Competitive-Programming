#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> appear(n+m+5,-1);
    vector<int> count(n+m+5,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        appear[a[i]] = 0;
    }
    long long ans = 0;
    for(int j = 1; j <= m; j++){
        int i,v;
        cin >> i >> v;
        i--;
        int last = a[i];
        count[last] += j-appear[last];
        appear[last] = -1;
        appear[v] = j;
        a[i] = v;
    }
    for(int i = 0; i < appear.size(); i++) {
        if(appear[i] != -1){
            count[i] += m+1-appear[i];
        }
    }
    for(int i = 0; i < count.size(); i++){
        ans+=1ll*(m+1)*m/2-1ll*(m-count[i])*(m-count[i]+1)/2;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
