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

void solve(){
    int n,k,z;
    cin >> n >> k >> z;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(z+1));
    ll ans = 0;
    rep(zz,0,z+1){
        rep(i,1,n+1){
            dp[i][zz] = dp[i-1][zz] + a[i-1];
            if(zz > 0 && i <n){
                dp[i][zz] = max(dp[i][zz],
                        dp[i+1][zz-1]+a[i-1]);
            }
            int curmoves = i-1+2*zz;
            if(curmoves == k){
                ans = max(ans,dp[i][zz]);
            }
        }
    }
    cout << ans << "\n";
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
