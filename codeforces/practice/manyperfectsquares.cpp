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
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    int best = 1;
    rep(i,0,n){
        rep(j,i+1,n){
            //get divisors of a[j]-a[i];
            //
            ll curval = a[j]-a[i];
            for(int d = 1; d*d < curval; d++){
                if(curval%d==0){
                    ll low = (curval/d - d);
                    if(low%2) continue;
                    low/=2;
                    ll x = low*low-a[i];
                    if(x < 0) continue;
                    int cnt = 0;
                    rep(ii,0,n){
                        ll cur = sqrt(a[ii]+x);
                        if(cur*cur==a[ii]+x) cnt++;
                    }
                    best = max(cnt,best);
                }
            }
        }
    }
    cout << best <<"\n";
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
