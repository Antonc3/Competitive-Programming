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
    int n; cin >> n;
    vi a(n+1);
    rep(i,1,n+1) cin >> a[i];
    vi pref(n+2,-1e9);
    vi suff(n+2,-1e9);
    for(int i = 1; i <= n; i++){
        pref[i] = max(pref[i-1],a[i]+i);
    }
    for(int i = n; i>= 1; i--){
        suff[i] = max(suff[i+1],a[i]-i);
    }
    int best = 0;
    for(int i = 2; i < n; i++){
        best = max(best,pref[i-1]+suff[i+1]+a[i]);
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
