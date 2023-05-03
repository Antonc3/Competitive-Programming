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

int getroudness(int v){
    int r = 0;
    while(v>0 && v%10==0){
        r++;
        v/=10;
    }
    return r;
}
void solve(){
    ll n,m;
    cin >> n >> m;
    int twos = 0;
    int fives = 0;
    ll nn = n;
    while(nn > 0 && nn%2 == 0){
        twos++;
        nn/=2;
    }
    while(nn > 0 && nn%5 == 0){
        fives++;
        nn/=5;
    }
    if(twos==fives){
        int mult = 1;
        while(mult *10<= m){
            mult*=10;
        }
        ll mult2 = 0;
        while(mult2+mult<=m){
            mult2+=mult;
        }
        cout<< n*mult2<<"\n";
        return;
    }
    else if(twos < fives){
        ll mult1 = 1;
        int cnt = 0;
        while(mult1*2 <= m && cnt < fives-twos){
            mult1*=2;
            cnt++;
        }
        while(mult1*10 <= m){
            mult1*=10;
        }
        ll mult2 = 0;
        while(mult2 +mult1<= m){
            mult2+=mult1;
        }
        cout << n*mult2<<"\n";
        return;
    }
    else{
        ll mult1 = 1;
        int cnt =0 ;
        while(mult1*5 <= m && cnt < twos-fives){
            mult1*=5;
            cnt++;
        }
        while(mult1*10 <= m){
            mult1*=10;
        }
        ll mult2 = 0;
        while(mult2 +mult1<= m){
            mult2+=mult1;
        }
        cout << n*mult2<<"\n";
        return;
    }
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
