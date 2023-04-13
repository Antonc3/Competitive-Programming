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
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    int c=0;
    vi cnt(9);
    rep(i,0,300){
        int cur = 0;
        rep(j,0,n){
            cur ^= (a[j]^i); 
        }
        if(cur==0){
            cout << i << "\n";
            return;
        }
    }
    cout <<"-1\n";
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
