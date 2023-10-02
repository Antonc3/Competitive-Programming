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
    int n,k;
    cin >> n >> k;
    vi x(k);
    vi c(k);
    rep(i,0,k) cin >> x[i];
    rep(i,0,k) cin >> c[i];

    vi cdiff(k);
    vi xdiff(k);
    cdiff[0] = c[0]-3;
    xdiff[0] = x[0]-3;
    if(c[0] > x[0]){
        cout << "NO\n";
        return;
    }
    rep(i,1,k){
        cdiff[i] = c[i]-c[i-1];
        xdiff[i] = x[i]-x[i-1];
        if(cdiff[i] > xdiff[i]){
            cout << "NO\n";
            return;
        }
    }
    string s = "abc";
    int i0 = 0;
    rep(i,0,k){
        int cnt = 0;
        while(cnt < cdiff[i]){
            s += ('d'+i);
            cnt++;
        }
        while(cnt < xdiff[i]){
            s+=('a'+i0);
            i0 = (i0+1)%3;
            cnt++;
        }
    }
    cout << "YES\n";
    cout << s << "\n";
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
