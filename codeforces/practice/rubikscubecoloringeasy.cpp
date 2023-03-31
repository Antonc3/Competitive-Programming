#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll M = 1e9+7;

ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res=(res*b)%M;
        b=(b*b)%M;
        e/=2;
    }
    return res;
}

void solve(){
    int k;
    cin >> k;
    ll f = (1ll<<k) - 2;
    ll ans = (6*fastpow(4,f))%M;
    cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t=1;
	while(t--){
		solve();
	}
}
