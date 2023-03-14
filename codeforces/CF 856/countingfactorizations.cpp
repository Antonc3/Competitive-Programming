#include <bits/stdc++.h>
using namespace std;
#define MAXVAL 1000005
#define M 998244353
typedef long long ll;

//ll fastpow(ll x, int exp){
//    if(exp == 0) return 1;
//    if(exp&1){
//        return (x*fastpow((x*x)%M,exp/2))%M;
//    }
//    else{
//        return fastpow((x*x)%M,exp/2)%M;
//    }
//}
ll fastpow(ll b, ll e){
	ll res = 1;
	while(e > 0){
		if(e % 2 == 1){
			res = res * b % M;
		}
		b = b * b % M;
		e /= 2;
	}
	return res;
}
 bool is_prime(ll n){
	if(n == 1){
		return false;
	}
	for(ll i = 2; i * i <= n; i++){
		if(n %i == 0){
			return false;
		}
	}
	return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n*2);
    for(int &x : v) cin >> x;
    sort(v.begin(),v.end());
    vector<pair<int,int>> comp_v;
    for(int i =0; i < n*2;){
        int cnt = 1;
        while(i+cnt<n*2 && v[i] == v[i+cnt]){
            cnt++;
        }
        comp_v.push_back({v[i],cnt});
        i+=cnt;
    }
    ////cout << comp_v.size()<<endl;
    vector<int> pr;
    vector<int> notprime;
    for(auto i : comp_v){
        if(is_prime(i.first))pr.push_back(i.second);
        else notprime.push_back(i.second);
    }
    int MAXN = 5050;
    vector<ll> fact(MAXN);
    vector<ll> factinv(MAXN);
    fact[0] = 1;
    factinv[0] = 1;
    for(int i=1;i<MAXN; i++){
        fact[i] = fact[i-1]*i%M;
    }
    for(int i =0; i < MAXN; i++){
        factinv[i] = fastpow(fact[i],M-2);
    }
    //cout << factinv[0] << endl;
    vector<vector<ll>> dp(MAXN,vector<ll>(MAXN));
    dp[0][0] = 1;
    for(int i = 1; i <= pr.size(); i++){
        int cur = pr[i-1];
        for(int j = 0; j <= pr.size(); j++){
            //cout << "cur " << cur << " last " <<dp[i-1][j] <<endl;
            dp[i][j] = factinv[cur]*dp[i-1][j]%M;
            if(j>0) dp[i][j]+=factinv[cur-1]*dp[i-1][j-1]; 
            dp[i][j]%=M;
            //cout << "i " << i << " j " << j << " dp[i][j] " << dp[i][j]<<endl;
        }
    }
    ll ans = dp[pr.size()][n];
    for(int i = 2; i <= n; i++){
        ans = ans*i%M;
    }
    for(int i : notprime){
        ans = ans*factinv[i]%M;
    }
    cout << ans << endl;
}
