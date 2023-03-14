#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree{
    vector<ll> S;
    int size;
    void init(int n){
        size = 1;
        while(size<n)size*=2;
        S.resize(2*size,0);
    }
    void set(int l, int r, ll v, int x, int lx, int rx){
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            S[x] +=v;
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
        if(rx-lx==1) return S[x];
        int m = (rx+lx)/2;
        if(i < m){
            return S[x] + query(i,x*2+1,lx,m);
        }
        else{
            return S[x] + query(i,x*2+2,m,rx);
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
            cout << st.query(i)<<"\n";
        }
    }
}
