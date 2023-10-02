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
const bool DEBUG = false;

void solve(){
    int m,n;
    cin >> m >> n;
    vi val(n);
    rep(i,0,n) cin >> val[i];
    vector<bitset<5005>> path(n);
    rep(i,0,n) path[i].set();
    vi indices(n);
    rep(i,0,n) indices[i] = i;
    rep(i,0,m){
        vi a(n);
        rep(j,0,n) cin >> a[j];
        sort(all(indices), [&](int l, int r){
                return a[l] < a[r];
            });
        bitset<5005> cur;
        cur.set();
        for(int j = 0; j < n;){
            int jj =j;
            while(jj < n && a[indices[jj]] == a[indices[j]]){
                cur.reset(indices[jj]);
                jj++;
            }
            while(j < jj){
                path[indices[j]] &= cur;
                j++;
            }
        }
    }
    vector<ll> dp(n,0);
    rep(i,0,n) dp[i] = val[i];
    ll best = 0;
    for(int i : indices){
        rep(j,0,n){
            if(path[i][j]){
                dp[j] = max(dp[j],dp[i] + val[j]);
            }
        }
    }
    rep(i,0,n) best = max(best,dp[i]);
    cout << best << "\n";
}

int main() {
	if(!DEBUG) cin.tie(0)->sync_with_stdio(0);
	if(!DEBUG) cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
