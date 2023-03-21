#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define F first
#define S second


struct segtree{
    vector<int> S;
    int size;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,-1e9);
    }
    void update(int i,int v, int x,int lx, int rx){
        if(rx-lx==1){
            S[x] = max(v,S[x]);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            update(i,v,x*2+1,lx,m);
        }
        else{
            update(i,v,x*2+2,m,rx);
        }
        S[x] = max(S[x*2+1],S[x*2+2]);
    }
    int calc(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) return -1e9;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        int s1 = calc(l,r,x*2+1,lx,m);
        int s2 = calc(l,r,x*2+2,m,rx);
        return max(s1,s2);
    }
};

void solve(){
    int n;
    cin >>n;
    vector<int> arr(n+1);
    vector<ll> pref(n+1);
    vector<pii> v;
    for(int i =1;i <= n; i++){
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
        v.push_back({pref[i],-i});
    }
    sort(v.begin(),v.end());
    vector<int> ord(n+1);
    for(int i = 1; i <= n; i++){
        ord[-v[i-1].S] = i;
    }
    vector<int> dp(n+1);
    segtree st;
    st.init(n+1);
    for(int i =1; i <= n; i++){
        dp[i] = dp[i-1]+(arr[i] > 0) -(arr[i] < 0);
        if(pref[i] > 0) dp[i] = i;
        //want to find 
        dp[i] = max(dp[i],st.calc(0,ord[i],0,0,st.size)+i);
        st.update(ord[i],dp[i]-i,0,0,st.size);
        //cout << dp[i] << " ";
    }
    cout << dp[n] << "\n";
}

int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
}
