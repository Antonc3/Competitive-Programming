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
    int n,k,c;
    cin >> n >> k >> c;
    vector<pii> ans;
    vector<int> cnt(n+1,0);
    vector<pii> rem;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        if(cnt[b] < c){
            if(ans.size() < k){
                ans.push_back({i,a});
                cnt[b]++;
            }
        }
        else{
            rem.push_back({i,a});
        }
    }
    int i = 0;
    while(i < rem.size() && ans.size() < k){
        ans.push_back(rem[i++]);
    }
    sort(ans.begin(),ans.end());
    for(pii i : ans){
        cout << i.second << endl;
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
