#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >> n >> s;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    int r = 0;
    ll sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(r < i){
            r=i;
            sum=0;
        }
        while(r < n && sum+arr[r] <= s){
            sum+=arr[r];
            r++;
        }
        ans = max(ans,r-i);
        sum-=arr[i];
    }
    cout << ans << endl;
}
