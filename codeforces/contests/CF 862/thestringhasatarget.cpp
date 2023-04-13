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
    int n;
    string s;
    cin >> n >> s;
    string ss = s;
    sort(all(ss));
    if(ss[0] != s[0]){
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ss[0]){
                string ans = ss[0] + s.substr(0,i) ;
                if(i < n-1){
                    ans += s.substr(i+1);
                }
                cout << ans << "\n";
                return;
            }
        }
    }
    if(ss[0] == ss[n-1]){
       cout << ss << "\n";
       return;
    }
    int front = 0;
    while(front < n && s[front] == ss[0]){
        front++;
    }
    for(int j = n-1; j >= front; j--){
        if(s[j] == ss[0]){
            string ans = s[j] + s.substr(0,j) ;
            if(j < n-1){
                ans += s.substr(j+1);
            }
            cout << ans << "\n";
            return;
        }
    }
    cout << s << "\n";
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
