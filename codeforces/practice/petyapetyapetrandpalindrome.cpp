#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const bool DEBUG = false;

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(auto &x : a) cin >> x;
    map<int,int> cnt;
    int total = 0;
    ll ans = 0;
    int endcnt = 0;
    int last = n-k/2-1;
    if(k==1){
        cout << "0\n";
        return;
    }
    for(int i = 0; i+k/2 < n; i+=2){
        if(i > k/2){
            cnt[a[i]]--;
            total--;
        }
        if(i != 0 && k-i-1 > i){
            cnt[a[k-i-1]]++;
            total++;
        }
        if(i+k-1 < n){
            cnt[a[i+k-1]]++;
            total++;
        }
        if(DEBUG) cout << "i: "<<i<<" total: " << total << " ans; " << ans << endl;
        if(DEBUG) cout << " cnt[a[i]] " << cnt[a[i]] << "\n";
        ans+=total-cnt[a[i]];
        if(i+2+k-1 >= n){
            int diff = last-i;
            if(DEBUG) cout << " last: " << last << "diff: " << diff << endl;
            if(last+diff < n){
                cnt[a[last+diff]]--;
                total--;
            }
        }
    }
    if(DEBUG) cout << "look at odds now\n";
    cnt.clear();
    total = 0;
    endcnt = 0;
    for(int i = 1; i+k/2< n; i+=2){
        if(i > k/2){
            cnt[a[i]]--;
            total--;
        }
        if(i != 0 && k-i-1 > i){
            cnt[a[k-i-1]]++;
            total++;
        }
        if(i+k-1 < n){
            cnt[a[i+k-1]]++;
            total++;
        }
        if(DEBUG) cout << "i: "<<i<<" total: " << total << " ans; " << ans << endl;
        if(DEBUG) cout << " cnt[a[i]] " << cnt[a[i]] << "\n";
        ans+=total-cnt[a[i]];
        if(i+2+k-1 >= n){
            int diff = last-i;
            if(last+diff < n){
                cnt[a[last+diff]]--;
                total--;
            }
        }
    
    }
   cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t=1;
	while(t--){
		solve();
	}
}
