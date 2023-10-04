#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segtree{
    vector<int> S;
    int size;
    int n;
    void init(vector<int> &a){
        n = a.size();
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,(1<<30)-1);
        build(a,0,0,n);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < n){
                S[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = S[x*2+1]&S[x*2+2];
    }
    int query(int l, int r, int x, int lx, int rx){
        if(l <= lx && rx <= r){
            return S[x];
        }
        if(r <= lx || rx <= l){
            return (1<<30)-1;
        }
        int m = (lx+rx)/2;
        int ls = query(l,r,x*2+1,lx,m);
        int rs = query(l,r,x*2+2,m,rx);
        return (ls&rs);
    }
    int getMaxR(int l, int k){
        int ll = l;
        int rr = n;
        int best = l;
        while(ll<=rr){
            int m = (ll+rr)/2;
            int res = query(l,m,0,0,n);
            if(res >= k){
                best = m;
                ll = m+1;
            }
            else{
                rr = m-1;
            }
        }
        return best;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    segtree st;
    st.init(a);
    int q;
    cin >> q;
    vector<int> ans;
    while(q--){
        int l, k;
        cin >> l >> k;
        l--;
        if(a[l] < k){
            ans.push_back(-1);
            continue;
        }
        int r= st.getMaxR(l,k);
        ans.push_back(r);
    }
    for(int x : ans) cout << x << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}