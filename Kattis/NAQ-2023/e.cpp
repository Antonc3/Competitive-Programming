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
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        v.push_back({a,b});
    }
    int cnt = 0;
    for(int i = 0; i+2 < n; i++){
        if(v[i].second < i+2){
            continue;
        }
        pii nxt2 = v[i+2];
        if(nxt2.first <= i){
            cnt++;
            i+=2;
        }
    }
    cout << cnt << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
