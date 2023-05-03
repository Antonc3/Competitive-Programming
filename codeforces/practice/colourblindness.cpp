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
    string a, b;
    cin >> n;
    cin >> a >> b;
    for(int i =0; i < n; i++){
        a[i] = (a[i] == 'G') ? 'B' : a[i];
        b[i] = (b[i] == 'G') ? 'B' : b[i];
    }
    cout << ((a==b) ? "YES" : "NO") << "\n";
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