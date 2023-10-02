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
    ll n,k,p;
    cin >> n >> k >> p;
    vector<ll> ans;
    for(ll i = 1; i*i <= n; i++){
        if(n%i != 0) continue;
        if(i*i==n){
            if(i <= k && i <= p){
                ans.push_back(i);
            }
            break;
        }
        //check if i is dosage
        if(i <= k && (n/i) <= p){
            ans.push_back(i);
        }
        
        if(i <= p && (n/i) <= k){
            ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(ll i : ans){
        cout << i << "\n";
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
