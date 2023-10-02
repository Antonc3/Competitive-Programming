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
    string inp;
    int x;
    cin >> inp >> x;
    int n = inp.length();
    vi s(n);
    rep(i,0,n){
        s[i] = inp[i]-'0';
    }
    vi ans(n);
    vector<int> visited(n,0);
    rep(i,0,n){
        if(i+x < n){
            if(i-x >= 0){
                if(s[i] == 0){
                    if(visited[i+x] && ans[i+x] == 1){
                        cout << "-1\n";
                        return;
                    }
                    if(visited[i-x] && ans[i-x] == 1){
                        cout << "-1\n";
                        return;
                    }
                    visited[i-x] = visited[i+x] = 1;
                }
            }
            else{
                if(visited[i+x] && s[i]!=ans[i+x]){
                    cout << "-1\n";
                    return;
                }
                visited[i+x] = true;
                ans[i+x] = s[i];
            }
        }
        else if(i+x >= n && i-x >= 0){
            if(visited[i-x] && s[i] != ans[i-x]){ 
                cout << "-1\n";
                return;
            }
            visited[i-x] = true;
            ans[i-x] = s[i];
        }
    }
    rep(i,0,n){
        if(!visited[i]) ans[i] = 1;
    }
    string res;
    rep(i,0,n){
        if(i+x < n && ans[i+x]==1) res+='1';
        else if(i-x >= 0 && ans[i-x] == 1) res+='1';
        else res+='0';
    }
    if(res != inp){
        cout << "-1\n";
        return;
    }
    rep(i,0,n) cout << ans[i];
    cout << '\n';
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
