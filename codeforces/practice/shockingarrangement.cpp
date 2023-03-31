#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
    }
    sort(all(a));
    ll diff = a[n-1]-a[0];
    if(diff==0){
        cout << "NO\n";
        return;
    }
    reverse(all(a));
    vi ans;
    
    //for(auto i : a) cout << i << " ";
    //cout << "\n";
    int r=n-1, l = 0;
    int csum = 0;
    rep(i,0,n){
        if(csum > 0){
            ans.push_back(a[r]);
            csum+=a[r];
            r--;
        }
        else{
            ans.push_back(a[l]);
            csum+=a[l];
            l++;
        }
    }
    cout << "YES\n";
    for(int i : ans) cout << i << " ";
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
