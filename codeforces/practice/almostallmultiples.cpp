#include <bits/stdc++.h>
using namespace std;

int intersect(int a, int mult){
    int best = -1;
    for(int i = mult+mult; i < a; i+=mult){
        if(a%i==0) return i;
    }
    return -1;
}
void solve(){
    int n,x;
    cin >> n>>x;
    if(n%x != 0){
        cout << "-1\n";
        return;
    }
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        ans[i] = i;
    }
    ans[x] = n;
    ans[n] = 1;
    ans[1] = x;
    int ci = x;
    int cv = n;
    int cur = intersect(cv,ci);
    while(cur != -1){
        swap(ans[cur], ans[ci]);
        ci = cur;
        cur = intersect(cv,ci);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";


}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
