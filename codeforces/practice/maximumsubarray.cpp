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
const bool DEBUG = false;

void solve(){
    int n,k,x;
    cin >> n >>k >>x;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<ll> prefixlow(n+1,0);
    vector<ll> prefixhigh(n+1,0);
    rep(i,1,n+1){
        prefixlow[i] = prefixlow[i-1]+a[i-1]-x;
        prefixhigh[i] = prefixhigh[i-1]+a[i-1]+x;
    }
    vector<int> maxsubarrlow(n+1);
    vector<int> maxsubarrhigh(n+1);
    maxsubarrlow[n] = n;
    maxsubarrhigh[n] = n;
    //o(nk)
    for(int i = n-1; i >= 0; i--){
        int prevmaxlow = maxsubarrlow[i+1];
        if(prefixlow[prevmaxlow] > prefixlow[i]){
            maxsubarrlow[i] = prevmaxlow;
        }
        else{
            maxsubarrlow[i] = i;
        }
        maxsubarrhigh[i] = i;
        for(int j = 1; i+j <=n && j <= k; j++){
            if(prefixhigh[i+j] > prefixhigh[maxsubarrhigh[i]]){
                if(DEBUG) cout <<"i: " << i << " i+j: " << i +j<<"\n";
                maxsubarrhigh[i] = i+j;
            }
        }
    }
    ll best = 0;
    if(x < 0){
        rep(i,0,n){
            int highind = maxsubarrlow[i];
            int ktoadd = k-i;
            if(ktoadd >0){
                if(DEBUG) cout <<"HERE\n";
                if(DEBUG) cout <<"ktoadd: " << ktoadd<<'\n';
                ll curbest =0;
                ll curadded = 0;
                for(int ind = i; ind < n; ind++){
                    if(DEBUG) cout << "ind " << ind << " curadded " << curadded <<"\n";
                    curadded+=a[ind];
                    if(ind +ktoadd >=n) curadded+=x;
                    else curadded-=x;
                    curbest = max(curbest,curadded);
                }
                best = max(best,curbest);
            }
            else{
                ll toadd = prefixlow[highind]-prefixlow[i];
                if(DEBUG) cout <<"i: " << i << "prefixhigh[i]; " << prefixhigh[i] <<" highind: " << highind<< " prefixhigh[highind]: " << prefixhigh[highind] << " nxthighind " << maxsubarrlow[highind] <<"\n";
                if(DEBUG) cout << "msarrlow[hind]: " <<maxsubarrlow[highind] << " prefixlow[msarrlow[highind]] " << prefixlow[maxsubarrlow[highind]] << " prefixlw[highind]: " << prefixlow[highind] <<"\n";
                best = max(best,toadd);
            }
        }
    }
    else{
        rep(i,0,n){
            int highind = maxsubarrhigh[i];
            int ktoadd = k-i;
            if(ktoadd > 0){
                if(DEBUG) cout <<"HERE\n";
                ll curbest = 0;
                ll curadded = 0;
                for(int ind = i; ind < n; ind++){
                    if(DEBUG) cout << "ind " << ind << " curadded " << curadded <<"\n";
                    curadded+=a[ind];
                    if(ind-i < k) curadded+=x;
                    else curadded-=x;
                    curbest = max(curbest,curadded);
                }
                best = max(best,curbest);
            }
            else{
                ll toadd = prefixhigh[highind]-prefixhigh[i];
                ll toaddafter = prefixlow[maxsubarrlow[highind]]-prefixlow[highind];
                int ni = min(i+k,n);
                ll otheradd = prefixhigh[min(n,i+k)]-prefixhigh[i];
                ll otheraddafter = prefixlow[maxsubarrlow[ni]]-prefixlow[ni];
                if(DEBUG) cout <<"i: " << i << "prefixhigh[i]; " << prefixhigh[i] <<" highind: " << highind<< " prefixhigh[highind]: " << prefixhigh[highind] << " nxthighind " << maxsubarrlow[highind] <<"\n";
                if(DEBUG) cout << "msarrlow[hind]: " <<maxsubarrlow[highind] << " prefixlow[msarrlow[highind]] " << prefixlow[maxsubarrlow[highind]] << " prefixlw[highind]: " << prefixlow[highind] <<"\n";
                if(DEBUG) cout <<"toadd: " << toadd <<" toaddafter: " << toaddafter<<"\n";
                best = max(best,toadd+toaddafter);
                best = max(best,otheradd+otheraddafter);
            }
        }
    }
    cout << best <<"\n";
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
