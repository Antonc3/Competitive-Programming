#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int cnt[100005][2];
void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n){
        cin >> a[i];
        cnt[a[i]][i%2]++;
    }
    sort(a.begin(),a.end());
    rep(i,0,n){
        cnt[a[i]][i%2]--;
    }
    bool good = true;
    rep(i,0,n){
        if(cnt[a[i]][0] != 0 || cnt[a[i]][1] != 0){
            good = false;
        }
        cnt[a[i]][0] = cnt[a[i]][1] = 0;
    }
    cout << ((good) ? "YES\n" : "NO\n");
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
