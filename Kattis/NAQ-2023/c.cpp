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
    double k;
    cin >> n >> k;
    vector<pair<int,double>> v;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        b--;
        v.push_back({-b,a});
    }
    double l = 0, r = 1e9;
    double best = 0;
    bool hasbeendone = false;
    for(int iter = 0; iter < 200; iter++){
        ///check for m;
        double m = (l+r)/2;
        bool possible = true;
        priority_queue<pair<int,double>> pq;
        for(int i = 0; i < n; i++){
            pq.push(v[i]);
            double neededAmount = m*k;
            while(pq.size() && neededAmount > 0.0){
                auto cur = pq.top();
                pq.pop();
                if(-cur.first < i) continue;
                if(cur.second < neededAmount){
                    neededAmount-=cur.second;
                }
                else{
                    cur.second = cur.second-neededAmount;
                    neededAmount = -1;
                    pq.push(cur);
                }
            }
            if(neededAmount > 0.0){
                possible = false;
                break;
            }
        }
        if(possible){
            l = m;
            best = m;
            hasbeendone = true;
        }
        else{
            r = m;
        }
    }
    if(hasbeendone){
        cout << setprecision(10) << best<<endl;
    }
    else {
        cout << "-1\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
