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
    int q;
    cin >> q;
    map<ll,ll> mp;
    map<ll,ll> best;
    unordered_map<ll,set<ll>> participate;
    unordered_map<ll,set<ll>> check;
    mp[0] = 1;
    while(q--){
        char op;
        ll x;
        cin >> op >> x;
        if(op=='+'){
            mp[x] = 1;
            for(ll i : participate[x]){
                check[i].erase(x);
            }
        }
        else if(op=='-'){
            mp.erase(x);
            for(ll i : participate[x]){
                check[i].insert(x);
            }
        }
        else{
            while(mp[best[x]]){
                participate[best[x]].insert(x);
                best[x]+=x;
            }
            ll res = best[x];
            if(check[x].size()){
                ll i = *check[x].begin();
                res = min(res,i);
            }
            cout << res <<"\n";
        }
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
