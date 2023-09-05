#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M =998244353;
ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e & 1) res = (res*b)%M;
        b = (b*b)%M;
        e/=2;
    }
    return res;
}
void solve(){
    int n,k;
    cin >> n >> k;
    // k! ways to order each thing 
    vector<vector<ll>> dp(n+1,vector<ll>(k,0));
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        ll sum = 0;
        for(int j = k-1; j >= 1; j--){
            sum = (sum+dp[i][j])%M;
            dp[i+1][j] = (dp[i+1][j] + sum) % M;
        }
        for(int j = 0; j < k; j++){
            if(j==k-1){
                dp[i+1][0] = (dp[i][j])%M;
                ans = (ans + dp[i][j]*fastpow(k,n-i-1)) % M;
            }
            else{
                dp[i + 1][j+1] = (dp[i+1][j+1] + dp[i][j]*(k-j))%M;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t  = 1;

    while(t--){
        solve();
    }
}