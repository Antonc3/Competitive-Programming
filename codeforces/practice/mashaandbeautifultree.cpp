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
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    if(n==1){
        cout << "0\n";
        return;
    }
    int h = 0;
    while((1<<h) < n) h++;
    int cnt = 0;
    rep(i,0,h){
        vi na;
        int diff = (1<<i);
        for(int j = 0; j < a.size(); j+=2){
            int cur = a[j];
            int nxt = a[j+1];
            if(cur > nxt) {
                cnt++;
                swap(cur,nxt);
            }
            if(nxt-cur == diff){
                na.pb(cur);
            }
            else{
                cout << "-1\n";
                return;
            }
        }
        a = na;
    }
    cout << cnt<<"\n";
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
