#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF =1e18;
const bool DEBUG = false;

void solve(){
    int n,k;
    cin >> n >> k;
    vi a(n);
    vi hot(k);
    vi cold(k);
    rep(i,0,n){
        cin >> a[i];
        a[i]--;
    }
    rep(i,0,k) cin >> cold[i];
    rep(i,0,k) cin >> hot[i];
    //vector<ll> dp(k+1,INF);
    vector<ll> dp(k+1,INF);
    dp[k] =hot[a[0]]- cold[a[0]];
    ll sum = cold[a[0]];
    ll best = 0;
    rep(i,1,n){
        int last = a[i-1];
        int cur = a[i];
        if(cur==last){
            sum+=hot[cur];
        }
        else{
            sum+=cold[cur];
            dp[last]=min(best,dp[cur]-cold[cur]+hot[cur]);
            best = min(dp[last],best);
        }
        ////if we choose to run cur on cpu1, then last doesnt change
        //vector<ll> ndp(k+1,INF);
        //if(DEBUG) cout << " i: " << i<<"\n";
        //rep(j,0,k+1){
        //    if(DEBUG) cout << dp[j] << " ";
        //    if(last==cur){
        //        ndp[j] = min(ndp[j],dp[j]+hot[a[i]]);
        //    }
        //    else{
        //        ndp[j] = min(ndp[j],dp[j]+cold[a[i]]);
        //    }
        //    if(cur==j){
        //        ndp[last] = min(ndp[last],dp[j]+hot[a[i]]);
        //    }
        //    else{
        //        ndp[last] = min(ndp[last],dp[j]+cold[a[i]]);
        //    }
        //}
        //if(DEBUG) cout << "\n";
        //dp = ndp;
    }
    cout << sum + best << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
