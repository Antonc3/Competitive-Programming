#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll M = 998244353;
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
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<ll> fact(n+1);
    vector<ll> invfact(n+1);
    fact[0] = 1;
    invfact[0] = 1;
    rep(i,1,n+1){
        fact[i] = (fact[i-1]*i)%M;
        invfact[i] = fastpow(fact[i],M-2);
    }
    ll ans = (((fact[n/3]*invfact[n/6])%M)*invfact[n/6])%M;
    for(int i = 0; i < n; i+=3){
        //choose two edges basically
        //if all edges are equal in this triangle,
        //then there are 3 ways to choose
        //if the two smallest are equal, there are two ways to choose
        //if the two largest are equal, or one is strictly smaller than the other two
        //then there is one way to choose
        vi curtuple(a.begin()+i,a.begin()+i+3);
        sort(all(curtuple));
        if(curtuple[0] == curtuple[2]){
            ans=(ans*3)%M;
        }
        else if(curtuple[0]==curtuple[1]){
            ans=(ans*2)%M;
        }
    }
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
