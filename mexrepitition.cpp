#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> seen(n+1,0);
    for(int &x : a){
        cin >> x;
        seen[x] = 1;
    }
    int missing = 0;
    for(int i = 0; i <= n; i++){
        if(!seen[i]) missing = i;
    }
    a.push_back(missing);
    vector<int> ans(n);
    //every n+1 mex repeitions, we go back to the original
    k = k%(n+1);
    for(int i = 0; i < n; i++){
        ans[i] = a[(n+1+i-k)%(n+1)];
    }
    for(int i : ans) cout << i << " ";
    cout << endl;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}