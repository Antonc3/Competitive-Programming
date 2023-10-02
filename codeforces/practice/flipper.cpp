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
    vi a(n);
    rep(i,0,n) cin >> a[i];
    if(n==1){
        cout << "1\n";
        return;
    }
    //if n is at the front we find n-1
    int f = n;
    if(a[0] == n) f = n-1;
    int r = -1;
    rep(i,0,n){
        if(a[i] == f){
            r = i-1;
            break;
        }
    }
    if (a[n - 1] == f) r = n-1; 
    int l;
    // 1 2 3 4 5
    // 4 3 2 5 1
    // 5 1 2 4 3
    for(l = r-1; l >= 0; l--){
        //compare to beginning
        if(a[l] > a[0]) continue;
        l++;
        break;
    }
    
    if( l > r) l = r;
    //cout << l << " r: " << r << '\n';
    vi ans;
    for(int i = r+1; i < n; i++){
        ans.pb(a[i]);
    }
    for(int i = r; i >= l; i--){
        ans.pb(a[i]);
    }
    for(int i = 0; i < l; i++){
        ans.pb(a[i]);
    }
    // 4 3 2 1 5
    // 1 2 3 4 5
    // check at end
    rep(i,0,n) cout << ans[i] << " ";
    cout << '\n';
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
