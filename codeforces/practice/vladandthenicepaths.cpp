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

const ll MOD = 1e9+7;
ll fastpow(ll a, ll e){
    ll res = 1;
    while(e > 0){
        if(e &1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        e/=2;
    }
    return (int) res;
}
void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n+1);
    rep(i,1,n+1) cin >> a[i];
    if(k==1){
        cout <<"1\n";
        return;
    }
    vector<pll> dp(n+1,{0,0});
    dp[0] = {1,0};
    //we want blocks of k
    //so there must be k distinct
    vector<ll> fact(n+1,1);
    vector<ll> invfact(n+1,1);
    rep(i,1,n+1){
        fact[i] = fact[i-1]*i%MOD;
        invfact[i] = fastpow(fact[i],MOD-2);
    }
    rep(i,1,n+1){
        int cnt = 1;
        for(int j = i-1; j >= 1; j--){
            if(a[j] == a[i]){
                cnt++;
                if(cnt == k){
                    dp[i] = {dp[j-1].first,dp[j-1].second+1};
                }
                else if(cnt > k){
                    if(dp[j-1].second+1 < dp[i].second){
                        break;
                    }
                    //how many ways are there to choose k unique positions from
                    //cnt different spots
                    //cnt!/k!/(cnt-k)!

                    ll ways = 1ll*dp[j-1].first*fact[cnt-2]%MOD;
                    ways = ways*invfact[k-2]%MOD;
                    ways = ways*invfact[cnt-k]%MOD;
                    dp[i] = {dp[i].first+ways%MOD,dp[i].second};
                }
            }
        }
        if(dp[i].second == dp[i-1].second){
            dp[i].first = (dp[i-1].first+dp[i].first)%MOD;
        }
        if(dp[i].second < dp[i-1].second){
            dp[i] = dp[i-1];
        }
    }
    cout << dp[n].first <<"\n";
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
