#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll M = 998244353;
void solve(){
    int n;
    cin >> n;
    vi x(n);
    vi y(n);
    vi open(n);
    vector<pii> allstarts;
    rep(i,0,n){
        int a,b,c;
        cin >> a >> b >> c;
        open[i] = c;
        x[i] = a;
        y[i] = b;
        allstarts.push_back({a,i});
        allstarts.push_back({b,i});
    }
    vi ystart(n);
    sort(all(allstarts));
    rep(i,0,2*n){
        if(y[allstarts[i].second] == allstarts[i].first){
            ystart[allstarts[i].second] = i;
        }
    }
    vector<ll> prefix;
    prefix.push_back(0);
    ll ans = (x[n-1]+1)%M;
    rep(i,1,2*n+1){
        auto cur = allstarts[i-1];
        int ii = cur.second;
        if(x[ii] == cur.first){
            //distance between start of portal and end
            ll dist = x[ii]-y[ii];
            ll cur= (M + prefix[i-1]-prefix[ystart[ii]] + dist)%M;
            //cout << "ystart: " << ystart[ii] << " cur pref: " << prefix[i-1] << " y pref: " << prefix[ystart[ii]] << " ii: " << ii << " cur: " << cur << " ans: " << ans <<endl;
            ll toadd = (M + prefix[i-1]+cur)%M;
            prefix.push_back(toadd);
            ans = (M + ans + ((open[ii]) ? cur : 0)) % M;
        }
        else{
            prefix.push_back(prefix.back());
        }
    }
    //for( auto i : prefix) cout << i << " ";
    //cout << "\n";
    cout << ans << "\n";
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t= 1;
	while(t--){
		solve();
	}
}
