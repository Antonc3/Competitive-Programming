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
const int MAXN = 20000005;
vi primes;
vi lpf;
void sieve(){
    lpf.resize(MAXN,0);
    rep(i,2,MAXN){
        if(lpf[i]==0){
            lpf[i] = i;
            primes.pb(i);
        }
        for(int j = 0; j < primes.size() && 1ll*i*primes[j] < MAXN; j++){
            lpf[i*primes[j]] = primes[j];
            if(primes[j] == lpf[i]) break;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<ll> dp(MAXN);
    vi cnt(MAXN);
    rep(i,0,n){
        int a;
        cin >> a;
        cnt[a]++;
    }
    sieve();
    rep(i,0,primes.size()) for(int j = MAXN/primes[i]; j >= 0; j--) cnt[j]+=cnt[j*primes[i]];
    for(int i = MAXN-1; i > 0; i--){
        dp[i] = 1ll*cnt[i]*i;
        rep(j,0,primes.size()){
            if(1ll*i*primes[j] >= MAXN) break;
            dp[i] = max(dp[i],dp[i*primes[j]]+1ll*i*(cnt[i]-cnt[i*primes[j]]));
        }
    }
    cout << dp[1] << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
