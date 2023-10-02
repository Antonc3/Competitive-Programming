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
    vi pos(m+1,0);

    int neg2 = 0, neg1 = 0;
    rep(i,0,n){
        int x;
        cin >> x;
        if(x >= 0){
            pos[x]=1;
        }
        else if(x==-1) neg1++;
        else neg2++;
    }
    int best = 0, cnt = 0;
    vi prefix(m+1,0);
    vi suffix(m+1,0);

    for(int i = 2; i <= m; i++){
        prefix[i] = prefix[i-1] + (pos[i-1] == 0);
    }
    for(int i = m-1; i >= 1; i--){
        suffix[i] = suffix[i+1] + (pos[i+1] == 0);
    }

    for(int i = 1; i <= m; i++){
        if(i == m){
            if(pos[i] == 0){
                cnt = min(prefix[i]+1,neg1);
            }
            else{
                cnt = min(prefix[i],neg1) + 1;
            }
            cnt += ((i-1)-prefix[i]);
            cnt += (m-i-suffix[i]);
            best = max(best,cnt);
        }
        if(i == 1){
            if(pos[i] == 0){
                cnt = min(suffix[i]+1,neg2);
            }
            else{
                cnt = min(suffix[i],neg2) + 1;
            }
            cnt += ((i-1)-prefix[i]);
            cnt += (m-i-suffix[i]);
            best = max(best,cnt);
        }
        if(pos[i]){
            //how many open spaces to the left?
            cnt = min(prefix[i],neg1) + min(suffix[i],neg2)+pos[i];
            cnt += ((i-1)-prefix[i]);
            cnt += (m-i-suffix[i]);
            best = max(best,cnt);
        }
    }
    cout << best << '\n';
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
