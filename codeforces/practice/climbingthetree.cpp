#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;


pll intersect(pll a, pll b){
    return {max(a.first,b.first),min(a.second,b.second)};
}

ll ceiling(ll v, ll d){
    if(v < 0ll) return 0ll;
    if(v%d==0ll) return v/d;
    return v/d+1;
}

void solve(){
    int q;
    cin >> q;
    pll lr = {1,1e18};
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int a,b,c;
            cin >> a >> b >> c;
            ll l = (c==1) ? 1 : 1ll*(a-b)*(c-2)+a+1;
            ll r = 1ll*(a-b)*(c-1)+a;
            pll curint = intersect(lr,{l,r});
            if(curint.first > curint.second){
                cout << "0 ";
            }
            else{
                lr = curint;
                cout << "1 ";
            }
        }
        else{
            int a,b;
            cin >> a >>b;
            //cout << "lr: " <<lr.first << " " << lr.second << "\n";

            ll ln = max(0ll,ceiling(lr.first-a,(a-b)));
            ll rn = max(0ll,ceiling(lr.second-a,(a-b)));
            //cout << "ln: " << ln << " rn: " << rn << "\n";
            if(ln==rn){
                cout << ln+1 << " ";
            }
            else cout << "-1 ";
        }
    }
    cout << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
