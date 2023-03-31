#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 200005

ll gcd(ll a, ll b){
    return (b==0) ? a : gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

int dp[MAXN][100];

void solve(){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i,0,n){
        cin >> a[i] >> b[i];
    }
    //between i and i+1
    
    ll g = 0;
    ll l = 1;
    int ans = 1;
    rep(i,0,n){
        g = gcd(g,1ll*a[i]*b[i]);
        l = lcm(l,b[i]);
        if(g%l!=0){
            ans++;
            g = 1ll*a[i]*b[i];
            l = b[i];
        }
    }
    cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
