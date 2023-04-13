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
    int n,x,p;
    cin >> n >> x >> p;
    int distmodn = n-x;
    //want to go some distance a*n+n-x for some a
    //so a*n+n-x = y*(y+1)/2 
    //for some 1 <= y <= p
    //we know n,p,x want to find y and a
    //y*(y+1)/2 mod n = n-x
    //y*(y+1)/2-n-x mod n = 0
    //y*(y+1)/2-x mod n = 0
    //(y^2)/2+y/2-x mod n = 0
    vi dp(n+1);
    //increase i by n
    for(ll i = 0, cnt = 0;cnt<=p-n&&cnt <= 1ll*n*n;cnt+=n, i+=(1ll*(n)*(n+1)/2)){
        dp[i%n] = 1;
    }
    for(int i = 1; i <= n; i++){
        ll cur = (1ll*i*(i+1)/2)%n;
        // cur+a=n-x
        if(dp[(2*n-x-cur)%n]){
            cout <<"YES\n";
            return;
        }
    }
    for(ll i = 0, cnt = 0;cnt<=1ll*n*n &&cnt <= p;cnt+=n, i+=(1ll*(n)*(n+1)/2)){
        dp[i%n] = 1;
    }
    for(int i = 1; i <= n && i <= p%n; i++){
        ll cur = (1ll*i*(i+1)/2)%n;
        // cur+a=n-x
        if(dp[(2*n-x-cur)%n]){
            cout <<"YES\n";
            return;
        }
    }
    cout <<"NO\n";


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
