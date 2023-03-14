#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >>n>>s;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    int l = 0;
    ll sum = 0;
    long long ans = 0;
    for(int r = 0; r < n; r++){
        sum+=arr[r];
        while(l < r && sum-arr[l] >= s){
            sum-=arr[l];
            l++;
        }
        if(sum >= s){
            ans+=l+1;
        }
    }
    cout << ans<<"\n";
}
