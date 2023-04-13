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
    //sieve
    vi primes(300005,1);
    vi foundprimes;
    for(int i = 2; i*i <= sz(primes); i++){
        if(primes[i]){
            for(int j = i*i; j < sz(primes); j+=i){
                primes[j] = 0;
            }
        }
    }

    //largest
    int n;
    cin >> n;
    vi a(n+1);
    rep(i,1,n+1) cin >> a[i];
    int st, en;
    cin >> st >> en;
    vector<vi> factors(300005);
    vector<vi> immfactors(n+1);
    rep(i,1,n+1){
        int cur = a[i];
        //cout << "cur: " << cur<< "\n";
        for(int j = 2; j*j <= cur; j++){
            if(j*j==cur && primes[j]){
                immfactors[i].pb(j);
                factors[j].pb(i);
                continue;
            }
            if(cur%j==0){
                //cout << " j " << j << "\n";
                if(primes[j]) immfactors[i].pb(j), factors[j].pb(i);
                if(primes[cur/j]) immfactors[i].pb(cur/j), factors[cur/j].pb(i);
            }
        }
        if(cur>1 && primes[cur]){
            immfactors[i].pb(a[i]);
            factors[a[i]].pb(i);
        }
    }
    vi par(n+1,-1);
    vi visited(300005);
    queue<int> q;
    q.push(st);
    par[st] = 0;
    while(!q.empty()){
        auto cur = q.front();
        //cout << "cur: " << cur << " a[cur] " << a[cur]<<"\n";
        q.pop();
        for(auto factor : immfactors[cur]){
            //cout << "factor: " << factor << "\n";
            if(visited[factor]) continue;
            visited[factor] = true;
            for(auto to : factors[factor]){
                if(par[to] != -1) continue;
                par[to] = cur;
                q.push(to);
            }
        }
    }
    if(par[en] == -1){
        cout << "-1\n";
        return;
    }
    vi shortestpath;
    for(int i = en; i != 0; i = par[i]){
        shortestpath.pb(i);
    }
    reverse(all(shortestpath));
    cout << shortestpath.size()<<"\n";
    for(int i : shortestpath) cout << i << " ";
    cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
