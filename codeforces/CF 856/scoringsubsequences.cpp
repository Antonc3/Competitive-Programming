#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x : v) cin >> x;
    int l = 0;
    vector<int> ans(n);
    for(int r = 0; r < n; r++){
        while(l < r && v[l] < (r-l+1)) l++;
        //while(l < r && v[l] <= (r-l+1)) l++;
        ans[r] = (r-l+1);
        //cout << "l " << l << " r " << r << endl;
    }
    for(int &x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
