#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector<int> interval(n+1,0);
    for(int i = 0; i < n; i++){
        if(a[i] <= b[i]) continue;
        interval[a[i]]--;
        interval[b[i]]++;
    }
    for(int i = 1; i <= n; i++){
        interval[i]+=interval[i-1];
    }
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        bool good = true;
        for(int k = i; k <= n; k+=i){
            good &= interval[k]==0;
        }
        if(good) ans.push_back(i);
    }
    cout << ans.size()<<"\n";
    for(int i : ans) cout << i << " ";
    cout << "\n";

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}