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

ll M = 1e9+7;
ll fastpow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = (res*b)%M;
        b=(b*b)%M;
        e/=2;
    }
    return res;
}
const ll ALPHLEN=27;
void solve(){
    int n;
    cin >> n;
    vector<tuple<int,string,int>> v;
    set<int> lens;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        lens.insert(s.length());
        v.push_back({s.length(),s,i});
    }
    sort(v.begin(),v.end());
    vector<pair<int,string>> ans;
    int k = 0;
    ll alphInv = fastpow(ALPHLEN,M-2);
    for(int len : lens){
        auto nxtLen = lens.upper_bound(len);
        if(nxtLen==lens.end()) break;
        if(len+1 != (*nxtLen)) continue;
        multiset<int> st;
        while(k < v.size() ){
            auto [clen, cur, ind] = v[k];
            if(clen != len) break;
            ll hash=0;
            for(int i = 0; i < clen; i++){
                hash = (hash*ALPHLEN+(cur[i]-'a'))%M;
            }
            k++;
            st.insert(hash);
        }
        int j = k;
        while(j < v.size()){
            auto [clen, cur, ind] = v[j];
            if(clen != len+1) break;
            ll lhash=0, rhash = 0;
            for(int i = clen-1; i>0; i--){
                rhash = (rhash+fastpow(ALPHLEN,clen-i-1)*(cur[i]-'a'))%M;
            }
            if(st.count(rhash)){
                ans.push_back({ind,cur});
                j++;
                continue;
            }
            for(int i = 0; i < clen; i++){
                lhash = (lhash*ALPHLEN+(cur[i]-'a'))%M;
                if(i < clen-1){
                    rhash = (M+rhash-(fastpow(ALPHLEN,clen-i-2)*(cur[i+1]-'a'))%M)%M;
                }
                ll totalHash = (lhash*fastpow(ALPHLEN,clen-i-2)+rhash)%M;
                if(st.count(totalHash) > 0){
                    ans.push_back({ind,cur});
                    break;
                }
            }
            j++;
        }
    }
    if(ans.empty()){
        cout << "NO TYPOS\n";
        return;
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i.second << endl;
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
