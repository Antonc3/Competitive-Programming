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
    map<int,int> mp;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        int cur = a[i];
        for(int j = 2; j*j <= cur; j++){
            while(cur%j == 0){
                mp[j]++;
                cur/=j;
            }
        }
        if(cur>1) mp[cur]++;
    }
    ll ans =0;

    int onecnt = 0;
    for(auto x : mp){
        if(x.second >= 2){
            ans+= x.second/2;
        }
        if(x.second%2==1){
            onecnt++;
        }
    }
    ans+=onecnt/3;
    cout << ans << "\n";
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
