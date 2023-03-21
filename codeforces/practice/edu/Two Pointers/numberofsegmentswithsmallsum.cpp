#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >>n>>s;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    int r = 0;
    ll sum = 0;
    long long ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && sum+arr[r] <= s){
            sum+=arr[r];
            r++;
        }
        ans+=r-l;
        sum-=arr[l];
    }
    cout << ans<<"\n";
}
