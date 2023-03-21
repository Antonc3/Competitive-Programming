#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
int n;
vector<ll> arr;

bool check(ll val){
    ll req = k*val;
    for(ll i = 0; i < n; i++){
        req-=min(val,arr[i]);
    }
    return req <= 0;
}

int main(){
    cin >> k;
    cin >> n;
    for(int i =0;i < n; i++){
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    ll l = 0, r = 2e15;
    ll best = 0;
    while( l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << best << endl;
}
