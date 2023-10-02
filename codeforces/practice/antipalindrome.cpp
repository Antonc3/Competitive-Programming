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
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 != 0) {
        cout << -1 << '\n';
        return;
    }
    vi violations(26);
    vi counts(26);
    for (int i = 0; i < n; i++) {
        counts[s[i] - 'a']++;
        if (counts[s[i] - 'a'] > n / 2) {
            cout << -1 << '\n';
            return;
        }
        if (s[i] == s[n - i - 1] && i < n / 2) {
            violations[s[i] - 'a']++;
        }
    }
    priority_queue<int> pq;
    for(int i = 0; i < 26; i++){
        if(violations[i] > 0){
            pq.push(violations[i]);
        }
    }
    int ans = 0;
    while(pq.size() > 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        num1--;
        num2--;
        if(num1 > 0) pq.push(num1);
        if(num2 > 0) pq.push(num2);
        ans++; 
    }
    if(pq.size()) ans += pq.top();
    cout << ans << '\n';
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
