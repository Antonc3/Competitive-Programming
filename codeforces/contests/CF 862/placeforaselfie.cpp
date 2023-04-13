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
    int n,m;
    cin >> n >> m;
    vi k(n);
    rep(i,0,n) cin >> k[i];
    sort(all(k));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        double vx = -(1.0*b)/(2*a);
        double vy = a*vx*vx+b*vx+c;
        if(vx==0 && vy==0){
            cout << "NO\n";
            continue;
        }
        if(c > 0){
            int da = 2*a;
            int db = b;
            double cc = 1.0*c/a;
            double roots = sqrt(cc);
            double left = (-roots)*da+b;
            double right = (roots)*da+b;
            int l = floor(left+1);
            int r = ceil(right-1);
            if(c==0){
                if( b > 0){
                    l = 1;
                    r = b-1;
                }
                else{
                    l = b+1;
                    r = -1;
                }
            }
            auto lb =lower_bound(all(k),l);
            if(lb==k.end()){
                cout << "NO\n";
                continue;
            }
            if((*lb) <= r){
                cout << "YES\n";
                cout << (*lb) << "\n";
                continue;
            }
            cout << "NO\n";
        }
        else{
            cout << "NO\n";
        }
        
    }
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
