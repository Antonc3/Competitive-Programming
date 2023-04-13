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
     int res = 0;
     cout << "+ " << n+1<<"\n";
     cout.flush();
     cin >> res;
     cout << "+ " << n+2<<"\n";
     cout.flush();
     cin >> res;
     pii largest = {0,0};

     rep(i,2,n+1){
         cout << "? 1 " << i << "\n";
         cout.flush();
         cin >> res;
         largest = max(largest,{res,i});
     }
     vi dist(n+1,0);
     vector<pii> points;
     points.push_back({0,largest.second});
     rep(i,1,n+1){
        if(i==largest.second) continue;
        cout << "? " << largest.second << " " << i << "\n";
        cout.flush();
        cin >> res;
        dist[i] = res;
        points.push_back({dist[i],i});
     }
     sort(all(points));
     vi forward;
     vi backward;
     int low = 1, high = n;
     rep(i,1,n+1){
        if(i&1){
            forward.pb(low);
            backward.pb(low);
            low++;
        }
        else{
            forward.pb(high);
            backward.pb(high);
            high--;
        }
     }
     reverse(all(backward));
     vi ans1(n+1), ans2(n+1);
     rep(i,1,n+1){
        pii cur = points[i-1];
        ans1[cur.second] = forward[i-1];
        ans2[cur.second] = backward[i-1];
     }
     cout <<"! ";
     rep(i,1,n+1){
         cout << ans1[i] << " ";
     }
     rep(i,1,n+1){
         cout << ans2[i] << " ";
     }
     cout <<"\n";
     cout.flush();
     cin >> res;
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
