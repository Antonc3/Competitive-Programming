#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;
    
    ll ans = 0;
    int r = 0;
    for(int l = 0; l < n; l++){
        while(r < n && arr[r]-arr[l] <= s){
            r++;
        }
        if(arr[r]-arr[l] > s){
            ans+=n-r;
        }
    }
    cout << ans << endl;
}
