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

const int MOD = 1e9+7;

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i,0,n) cin >> a[i];

    vector<vi> dp(n+1,vi(64,0));
    rep(i,1,n+1){
        rep(mask,0,64){
            dp[i][mask] += dp[i-1][mask];
            dp[i][mask] %= MOD;
            dp[i][a[i-1]&mask] += dp[i-1][mask];
            dp[i][a[i-1]&mask] %= MOD;
        }
        dp[i][a[i-1]] += 1;
        dp[i][a[i-1]] %= MOD;
    }
    int ans = 0;
    rep(i,0,64){
        if(__builtin_popcount(i) == k) ans  = (ans+dp[n][i])%MOD;
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
