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

ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = res*b%MOD;
        b = b*b%MOD;
        e/=2;
    }
    return res;
}

void solve(){
    int n,m;
    cin >> n >> m;
    map<int,int> cnt;
    vi values;
    rep(i,0,n){
        int a;
        cin >> a;
        if(cnt[a] == 0){
            values.pb(a);
        }
        cnt[a]++;
    }
    if(m == 1) {
        cout << n << "\n";
        return;
    }
    sort(all(values));
    int vsz = sz(values);
    int l = 0, r = 0; 
    ll ans = 0;
    ll cur = cnt[values[0]];
    while(r+1 < vsz){
        r++;
        if(values[r] != values[r-1]+1){
            l = r;
            cur = cnt[values[r]];
            continue;
        }
        cur = cur*cnt[values[r]]%MOD;
        if(r-l >= m-1){
            ans+=cur;
            ans%=MOD;
            cur = cur*fastpow(cnt[values[l]],MOD-2)%MOD;
            l++;
        }
    }
    cout << ans <<'\n';
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
