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
    int n, s0, s1;
    cin >> n >> s0 >> s1;
    vector<pii> a(n);
    rep(i,1,n+1){
        int x;
        cin >> x;
        a[i-1] = {x,i};
    }
    sort(all(a));
    vi fr;
    vi sr;
    int frsum = 0;
    int srsum = 0;
    for(int i = n-1; i >= 0; i--){
        int cur = a[i].first;
        int addfirst = cur*s0;
        int addsecond = cur*s1;
        if(frsum+s0 < srsum+s1){
            fr.pb(a[i].second);
            frsum+=s0;
        }
        else{
            sr.pb(a[i].second);
            srsum+=s1;
        }
    }
    cout << fr.size() << " ";
    for(auto i : fr) cout << i << " ";
    cout << "\n";
    cout << sr.size() << " ";
    for(auto i : sr) cout << i << " ";
    cout << "\n";
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
