#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long item;

struct segtree{
    vector<item> S;
    vector<item> op;
    int size;

    item NEUTRAL_ELEMENT=LLONG_MAX;
    item modify_op(item a, item b){
        return a|b;
    }
    item calc_op(item a, item b){
        return a&b;
    }
    void apply_mod_op(item &a, item b){
        a = modify_op(a,b);
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,0ll);
        op.assign(2*size,0ll);
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_mod_op(S[x],v);
            apply_mod_op(op[x],v);
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        S[x] = modify_op(calc_op(S[x*2+1],S[x*2+2]),op[x]);
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }
    item query(int l, int r,int x, int lx, int rx){
        if(rx <= l || r <= lx) return LLONG_MAX;
        if(l <= lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        auto q1 = query(l,r,x*2+1,lx,m);
        auto q2 = query(l,r,x*2+2,m,rx);
        return modify_op(calc_op(q1,q2),op[x]);
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
            st.modify(l,r,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << st.query(l,r)<<"\n";
        }
    }
    return 0;
}
