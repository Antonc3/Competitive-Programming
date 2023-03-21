#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const bool DEBUG = false;

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    int ans = n+1;
    vector<int> store(s+1,-1);
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        if(cur == s) ans = 1;
        for(int j = s-cur; j >= 0;  j--){
            if(DEBUG)cout << store[j] << " ";
            if(store[j] == -1) continue;
            store[j+cur] = max(store[j+cur],store[j]);
            if(j+cur == s){
                if(DEBUG)cout << "ans found: " << store[s] << " " << i << "\n";
                ans = min(ans, i-store[s]+1);
            }
        }
        store[cur] = i;
        if(DEBUG)cout << endl;
    }
    if(ans == n+1) cout << -1 << "\n";
    else cout << ans << endl;
}
