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
    int MAXA = 0;
    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,0,n){
        int x;
        cin >> x;
        MAXA = max(x,MAXA);
        mp[x]++;
    }
    MAXA++;
    int cuberoot = cbrt(MAXA)+1;
    ll ans =0;
    for(auto i : mp){
        int v = i.first;
        ll cnt = i.second;
        vi facts;
        if(cnt >=3){
            ans +=cnt*(cnt-1)*(cnt-2);
        }
        if(v != 1 &&1ll*v*v < MAXA){
            ans+=cnt*mp[1]*mp[v*v];
        }
        for(int j = 2; v*j <= MAXA &&j <= cuberoot && j*j <= v; j++){
            if(v%j) continue;
            int f1 = j;
            int f2 = v/j;
            if(f1 != f2 &&1ll*v*f2 < MAXA){
                if(mp.count(v*f2) > 0 && mp.count(f1) > 0) ans+=cnt*mp[v*f2]*mp[f1];
            }
            if(1ll*v*f1 < MAXA &&mp.count(v*f1) > 0 && mp.count(f2) > 0) ans+=cnt*mp[v*f1]*mp[f2];
        }
    }
    cout << ans <<"\n";
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
