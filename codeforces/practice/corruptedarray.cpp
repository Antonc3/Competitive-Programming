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
    vi b(n+2);
    map<int,int> cnt;
    ll sum = 0;
    for(auto &x : b){
        cin >> x;
        cnt[x]++;
        sum+=x;
    }
    rep(i,0,n+2){
        int cur = b[i];
        ll csum = sum-cur;
        cnt[cur]--;
        if(csum-cur <= 1e9 && cnt[csum-cur] > 0){
            int ff = false;
            int fs = false;
            for(auto j : b){
                if(j==cur && !ff) {
                    ff = true;
                    continue;
                }
                if(j==csum-cur && !fs) {
                    fs = true;
                    continue;
                }
                cout << j << " ";
            }
            cout << "\n";
            return;
        }
        cnt[cur]++;
    }
    cout << "-1\n";
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
