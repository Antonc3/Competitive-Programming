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
    vi h(n);
    ll total = 0;
    rep(i,0,n){
        cin >> h[i];
        total+=h[i];
    }
    vector<vector<ll>> dp(2,vector<ll>(n));
    stack<pii> st;
    rep(rev,0,2){
        rep(i,0,n){
            int cur = h[i];
            while(st.size() && st.top().first >= cur-(i-st.top().second)){
                st.pop();
            }
            int lastind = -1;
            if(st.size()) lastind = st.top().second;

            ll d1 = 1ll*h[i]*(h[i]+1)/2-max(0ll,max(0ll,1ll*(h[i]-(i-lastind)))*(h[i]-(i-lastind)+1)/2);
            dp[rev][i] = d1;
            if(st.size()) dp[rev][i]+=dp[rev][lastind];
            st.push({h[i],i});
        }
        reverse(all(h));
        st = stack<pii>();
    }
    ll best = total;
    rep(i,0,n){
        ll cur = total-dp[0][i]-dp[1][n-1-i] + 2*h[i];
        best = min(best,cur);
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
