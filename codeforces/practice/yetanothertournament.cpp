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
    vi a(n);
    vi b(n);
    rep(i,0,n){
        cin >> a[i];
        b[i] = i;
    }
    sort(all(b),[&](int l, int r)->bool{
            if(a[l] == a[r]) return l < r;
            return a[l] < a[r];
        });
    vi cost(n);
    cost[0] = a[b[0]];
    rep(i,1,n){
        cost[i] = cost[i-1] + a[b[i]];
    }
    vi visited(n+5,1);
    visited[n] =0;
    int best = n+1;
    if(n > 1){
        if(a[1] <= m){
            best = n-1;
        }
    }
    //have already defeated
    //wins = 3
    // i = 2,
    // if defeated i=3, then we tie with 3
    // if lose 3 and deafeted i=2, then we place between 2 and 3
    // if we lose to 3 and lose to 2, then we tie with 2
    //0, 1, 2, 3, ..., n-1
    //n=5
    // 0,1,2,3,4
    for(int i = n-1; i >= 0; i--){
        //can defeat i dudes
        //i+1 has also defeated i dudes
        //if have defeated i+1 already
        if(cost[i] <= m && visited[i+1]){
            best = min(best,n-i-1);
        }
        else if(cost[i] <= m){
            best = min(best,n-i);
        }
        //have defeated i+1+1
        if(i < n-1 && cost[i] + a[i+1] <= m && !visited[i+1]){
            best = min(best,n-i-1);
        }
        //have defeated i+1 + 1
        if(i < n-2 && cost[i] + a[i+2] <= m && !visited[i+2]){
            best = min(best,n-(i+2));
        }
        visited[b[i]] = 0;
    }
    cout << best<<'\n';
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
