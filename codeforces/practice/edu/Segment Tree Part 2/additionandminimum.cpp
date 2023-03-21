#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long item;

struct segtree{
    vector<item> S;
    vector<item> S2;
    int size;

    item NEUTRAL_ELEMENT=LLONG_MAX;

    item merge(item a, item b){
        return min(a,b);
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,0ll);
        S2.assign(2*size,0ll);
    }
    void add(int l, int r, int v, int x, int lx, int rx){
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            S[x] += v;
            S2[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        add(l,r,v,x*2+1,lx,m);
        add(l,r,v,x*2+2,m,rx);
        S[x] = min(S[x*2+1],S[x*2+2])+S2[x];
    }
    void add(int l, int r, int v){
        add(l,r,v,0,0,size);
    }
    item query(int l, int r,int x, int lx, int rx){
        if(rx <= l || r <= lx) return LLONG_MAX;
        if(l <= lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        auto q1 = query(l,r,x*2+1,lx,m);
        auto q2 = query(l,r,x*2+2,m,rx);
        return min(q1,q2)+S2[x];
    }
    item query(int l, int r){
        return query(l,r,0,0,size);
    }
};
int main(){
    int n,m;
    cin >> n >> m;

    segtree st;
    st.init(n);
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l, r, v;
            cin >> l >> r >> v;
            st.add(l,r,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << st.query(l,r)<<"\n";
        }
    }
    return 0;
}
