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
    
    ll sum = 0;
    ll ans = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        sum+=arr[r];
        while(l < r &&sum > s){
            sum-=arr[l];
            l++;
        }
        if(sum <= s){
            ans+= 1ll*(r-l+1)*(r-l+2)/2;
        }
    }
    cout << ans << endl;
}
