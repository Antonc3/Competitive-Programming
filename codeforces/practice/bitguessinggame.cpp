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

const bool DEBUG = false;
void solve(){
    int ans =0;
    int cnt;
    cin >> cnt;
    int steps = 0;
    int k = 0;
    while(cnt > 0 && steps < 30){
        cout << "- " << (1<<k) << "\n";
        steps++;
        cout.flush();
        int cnt2;
        cin >> cnt2;
        if(DEBUG) cout << "cnt2: " << cnt2 << " cnt: "<< cnt <<"\n";
        if(cnt2 < cnt){
            ans += (1<<k);
            k++;
        }
        else{
            int diff = cnt2-cnt;
            int nk = k+diff+1;
            int d2 = (1<<nk)-1;
            if(k > 0) d2 -= ((1<<(k))-1);
            ans += (1<<k) + d2;
            cout << "- " << d2 << "\n";
            if(DEBUG) cout << "k " << k << " d2: " << d2 << " nk: " << nk <<'\n';
            cout.flush();
            cin>>cnt2;
            k = nk+1;
            steps++;
        }
        cnt = cnt2;
    }

    //start from right and go left
    //1011110111
    //if we subtract 2^k and cnt decreases we know there was a 1 bit at 2^k
    //otherwise, if cnt increases, the number it increases by is the number of 0's there were ahead of k
    //so for example
    //1000011000
    //if we take k = 0, 
    //then we get
    //1000010111
    //so there were 2 0's ahead of k, and now 0 zero ahead of those 2 1's
    cout << "! " << ans <<'\n';
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
