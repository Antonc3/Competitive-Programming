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
    int n,q;
    cin >> n >> q;
    vi a(n+1);
    rep(i,1,n+1) cin >> a[i];
    vi prefix(n+1,0);
    rep(i,2,n){
        prefix[i] = prefix[i-1];
        if(a[i-1] >= a[i] && a[i] >= a[i+1]) prefix[i]++;
    }
    prefix[n] = prefix[n-1];
    rep(_,0,q){
        int l, r;
        cin >>l >> r;
        if(l==r){ cout << 1 << "\n"; continue;}
        cout << (r-l)+1-(prefix[r-1]-prefix[l])<<'\n';
    }
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
