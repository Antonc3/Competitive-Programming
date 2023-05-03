#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

ll MOD = 998244353;

ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res=(b*res)%MOD;
        e/=2;
        b = (b*b)%MOD;
    }
    return res;
}

void solve(){
    int n;
    string a,b;
    cin >> n >> a >> b;
    vi invnum(n+10);
    invnum[0] = 0;
    rep(i,1,n+10){
        invnum[i] = fastpow(i,MOD-2);
    }
    int difcnt = 0;
    rep(i,0,n){
        if(a[i] != b[i]) difcnt++;
    }
    vector<ll> dp(n+1,0);
    dp[0] = 0;
    dp[1] = fastpow(2,n)-1;
    //
    //dp[i] = i/n*dp[i-1]+(n-i)/n*dp[i+1]
    //dp[i+1] = n/(n-i)*dp[i]*i/(n-i)*dp[i-1]+
    for(ll i = 2; i < n; i++){
        ll x = ((i-1)*invnum[n])%MOD;
        ll part1 = dp[i-1]-x*dp[i-2]-1;
        part1%=MOD;
        part1+=MOD;
        part1%=MOD;
        part1*=n;
        part1%=MOD;
        dp[i] = part1*invnum[n-i+1]%MOD;
    }
    dp[n] = dp[n-1]+1;
    cout << dp[difcnt] <<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
