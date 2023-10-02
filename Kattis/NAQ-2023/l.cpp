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
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> w(n);
    bool minseen = false, maxseen = false;
    for(int i = 0; i < n-1; i++){
        int k;
        cin >> k;
        if(k == a) minseen = true;
        if(k == b) maxseen = true;
    }
    if(! minseen && !maxseen){
        cout << "-1\n";
        return;
    }
    if(minseen && !maxseen){
        cout << b<<"\n";
        return;
    }
    if(maxseen && !minseen){
        cout << a<<"\n";
        return;
    }
    for(int i = a; i <= b; i++) cout << i << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
