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
    int n,h;
    cin >> n >> h;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    sort(all(a));
    int serums[] = {2,2,3};
    //serum start
    ll best = 0;
    rep(ss,0,3){
        vector<vector<pll>> dp(4,vector<pll>(n+1,{h,0}));
        if(DEBUG) cout << "FIRST vals: \n";
        for(int i = 0; i < 4; i++){
            if(i > 0){
                dp[i][0] = dp[i-1][0];
                dp[i][0].first*=serums[(i+ss)%3];
            }
            for(int j = 1; j < n+1; j++){
                pll cur = dp[i][j-1];
                if(cur.first > a[j-1]){
                    cur.first += a[j-1]/2;
                    cur.second++;
                }
                if( i > 0){
                    pll cur2 = dp[i-1][j];
                    cur2.first*=serums[(i+ss)%3];
                    if(cur2.second > cur.second){
                        cur = cur2;
                    }
                    if(cur2.second == cur.second){
                        cur = max(cur,cur2);
                    }
                }
                if( i > 0){
                    pll cur2 = dp[i-1][j-1];
                    cur2.first*=serums[(i+ss)%3];
                    if(cur2.first > a[j-1]){
                        cur2.first += a[j-1]/2;
                        cur2.second++;
                    }
                    if(cur2.second > cur.second){
                        cur = cur2;
                    }
                    if(cur2.second == cur.second){
                        cur = max(cur,cur2);
                    }
                }
                if(DEBUG) cout << cur.first << " ";
                dp[i][j] = cur;
            }
            if(DEBUG) cout <<"\n";
        }
        if(DEBUG) cout << "second vals --------------------------------\n";
        rep(i,0,4){
            rep(j,1,n+1){
                if(DEBUG) cout << dp[i][j].second << " ";
            }
            if(DEBUG) cout << "\n";
        }
        best = max(best,dp[3][n].second);
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
