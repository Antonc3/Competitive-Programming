#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

ll MOD = 998244353;
ll gcd(ll a, ll b){
    return (b==0) ? a : gcd(b,a%b);
}
ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}
void solve(){
    //sieve
    vi primes(300005,1);
    rep(i,2,primes.size()){
        if(primes[i]){
            for(ll j = 1ll*i*i; j < primes.size(); j+=i){
                primes[j] = 0;
            }
        }
    }
    ll n, m;
    cin >> n >> m;
    // all numbers up to i are not divisible by 
    // is there any unambiguos arrays of length 3?
    // remmults: 3 clcm: 2 cnt: 0 cntnotincluded 6
    // 0
    // remmults: 5 clcm: 6 cnt: 108 cntnotincluded 18
    // 18
    // remmults: 6 clcm: 7 cnt: 1188 cntnotincluded 18
    ll ans = 0;
    ll mm = m%MOD;
    ll cnt = 0;
    ll clcm = 1;
    ll cntNotIncluded = mm;
    rep(i,2,n+1){
        //numbers that are not multiples of clcm
        if(primes[i]){
            clcm = min(LLONG_MAX,clcm*i);
        }
        ll remmults = m-m/clcm;
        cnt = (cnt+cntNotIncluded*(remmults%MOD))%MOD;
        ans = (ans+cnt)%MOD;
        cnt = (cnt * mm) % MOD;
        cntNotIncluded = (cntNotIncluded*((m-remmults)%MOD))%MOD;
    }
    cout << ans << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
