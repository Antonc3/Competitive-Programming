#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll k;
vector<ll> a, b;

bool check(ll val){
    ll sum=0;
    for(int i = 0; i < n; i++){
        sum+=lower_bound(b.begin(),b.end(),val-a[i])-b.begin();
    }
    return sum < k;
}

int main(){
    cin >> n >> k;
    a = vector<ll>(n);
    b = vector<ll>(n);
    for(ll &x : a) cin >> x;
    for(ll &x : b) cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll l = 0, r = 2e9;
    ll best = l;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            best =mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << best << endl;
}
