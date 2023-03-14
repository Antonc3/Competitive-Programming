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
    ll total = 0;
    for(auto x : arr) total+=x;
    
    int r = 0;
    ll sum = 0;
    ll bestlen = LLONG_MAX;
    int bestind = 1;
    ll len = (s/total)*n;
    s%=total;
    for(int l = 0; l < n; l++){
        while(sum < s){
            sum+=arr[r];
            r++;
            r%=n;
            len++;
        }
        if(sum >= s){
            if(len < bestlen){
                bestlen = len;
                bestind = l+1;
            }
        }
        sum-=arr[l];
        len--;
    }
    cout << bestind << " " << bestlen<<"\n";
}
