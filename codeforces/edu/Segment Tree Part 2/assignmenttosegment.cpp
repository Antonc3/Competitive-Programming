#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree{
    vector<ll> S;
    int size;
    ll merge(ll a, ll b){
        return (a >= 0) ? a : b;
    }
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        S.assign(2*size,-1);
    }
    void set(int l, int r, ll v, int x, int lx, int rx){
        if(rx <= l || r <= lx) return;
        if(rx-lx > 1){
            S[x*2+1] = merge(S[x],S[x*2+1]);
            S[x*2+2] = merge(S[x],S[x*2+2]);
            S[x] = -1;
        }
        if(l <= lx && rx <= r){
            S[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        set(l,r,v,x*2+1,lx,m);
        set(l,r,v,x*2+2,m,rx);
    }
    void set(int l, int r, ll v){
        set(l,r,v,0,0,size);
    }
    ll query(int i, int x, int lx, int rx){
        if(S[x] >= 0) return S[x];
        if(rx-lx==1) return S[x];
        int m = (rx+lx)/2;
        if(i < m){
            return query(i,x*2+1,lx,m);
        }
        else{
            return query(i,x*2+2,m,rx);
        }
    }
    ll query(int i){
        return query(i,0,0,size);
    }
};
int main(){
    int n,m;
    cin >> n  >> m;
    segtree st;
    st.init(n+1);
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l,r,v;
            cin >> l >> r >> v;
            st.set(l,r,v);
        }
        else{
            int i;
            cin >> i;
            ll res = st.query(i);
            res = (res >= 0) ? res : 0;
            cout << res<<"\n";
        }
    }
}
