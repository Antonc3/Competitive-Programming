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
    int d1, d2,d3;
    cout << "? 1 1\n";
    cout.flush();
    cin >> d1;
    if(d1 >= n){
        cout << "? 1 " << 1+d1 << "\n";
        cout.flush();
        cin >> d2;
        cout << "! " << 1+d2 << " " << 1+d1 << "\n";
        cout.flush();
        return;
    }
    if(d1 >= m){
        cout << "? " << 1+d1 << " 1 " << "\n";
        cout.flush();
        cin >> d2;
        cout << "! " << 1+d1 << " " << 1+d2 << "\n";
        cout.flush();
        return;
    }
    cout << "? " << 1+d1 << " 1 " << "\n";
    cout.flush();
    cin >> d2;
    
    cout << "? 1 " << 1+d1 << "\n";
    cout.flush();
    cin >> d3;
    if(d1 == d2){
        cout << "! " << 1+d3 << " " << 1+d1 <<"\n";
        cout.flush();
        return;
    }
    cout << "! " << 1+d1 << " " << 1+d2 << "\n";
    cout.flush();
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
