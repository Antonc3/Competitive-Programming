#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M =1e9+7;

ll fastpow(ll base, ll exp){
    if(exp == 0) return 1;
    ll ans = 1;
    while(exp > 0){
        if(exp&1){
            ans = ans*base%M;
        }
        exp/=2;
        base=base*base%M;
    }
    return ans;
    //return fastpow(base*base%M,exp/2)*((exp&1) ? base : 1)%M;
}

int main(){
    int n;
    cin >> n;
    n++;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    vector<ll> fact(n+arr[0]+1,0);
    vector<ll> invfact(n+arr[0]+1,0);
    fact[0] = 1;
    invfact[0] = 1;
    for(int i = 1; i < n+arr[0]+1; i++){
        fact[i] = fact[i-1]*i%M;
        invfact[i] = fastpow(fact[i],M-2)%M;;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]==0) break;
        ans =(ans+ ((fact[i+arr[i]]*invfact[i+1]%M)*invfact[arr[i]-1])%M)%M;
    }
    cout << ans << endl;
}
