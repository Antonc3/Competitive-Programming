#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
vector<ll> arr;

bool check(ll val){
    //can we form k groups with sum less than or equal to val
    int l = 0;
    for(int i = k-1; i >= 0; i--){
        ll sum = 0;
        while(l < n-i && sum+arr[l] <=val){
            sum+=arr[l];
            l++;
        }
    }
    //cout << "val " << val << " " << l << endl;
    return l==n;
}

int main(){
    cin >> n >> k;
    arr = vector<ll>(n);
    for(ll &x : arr) cin >> x;
    ll l = 0, r = 1e15;
    ll best = 0;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << best << endl;
}
