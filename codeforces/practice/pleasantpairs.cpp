#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<pair<int,int>> pairs;
    for(int i = 0; i < n; i++){
        pairs.push_back({a[i],i+1});
    }
    sort(a.begin(),a.end());
    sort(pairs.begin(),pairs.end());
    int ans = 0;
    //i+j < 2n;
    for(int i = 0; i < n && a[i]*a[i] <= 2*n; i++){
        for(int j = i+1; j < n && a[i]*a[j] <= 2*n; j++){
            if(pairs[i].second +pairs[j].second == a[i]*a[j]) ans++;
        }
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
