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
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vi dp(n+1);
    dp[0] = 1;
    rep(i,1,n+1){
        if(dp[i-1]){
            if(i+a[i-1] <= n) dp[i+a[i-1]] = 1;
        }
        if(i-a[i-1]-1 >= 0 && dp[i-a[i-1]-1]) dp[i] = 1; 
    }
    cout << ((dp[n]) ? "YES\n" : "NO\n");
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
