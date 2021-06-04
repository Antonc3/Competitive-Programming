#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
	ll x,y,d;
	cin >> d >> x >> y;
	if(x == y){
		cout << d+1<<endl;
		return;
	}
	ll ans = d+1;
	for(ll i = 0; i <= d; i++){
		ll cx = x+i;
		ll cy = y+i;
		ll c3 = 1;
		while(c3 <= max(cx,cy)){
			// cout << "c3: " << c3<< " " << cx/c3 << " cy " << cy/c3<<endl;
			if(((cx/c3)%3)%2 != (((cy/c3)%3)%2)){
				ans--;
				// cout << "bad: ";
				break;
			}
			c3*=3;
		}
		// cout << cx << " " <<cy <<endl;
	}
	cout << ans<<endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}