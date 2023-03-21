#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long item;

struct segtree{
    vector<item> S;
    vector<item> op;
    int size;

    item NEUTRAL_ELEMENT=0;
    item NO_OP = -1;
    item modify_op(item a, item b,item len){
        return b*len;
    }
    item calc_op(item a, item b){
        return a+b;
    }
    void apply_mod_op(item &a, item b, item len){
        a = modify_op(a,b,len);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        if(op[x] == NO_OP) return;
        int m = (rx+lx)/2;
        apply_mod_op(S[x*2+1], op[x], m-lx);
        apply_mod_op(op[x*2+1], op[x], 1);
        apply_mod_op(S[x*2+2], op[x], rx-m);
        apply_mod_op(op[x*2+2], op[x], 1);
        op[x] = NO_OP;
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,0);
        op.assign(2*size,-1);
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_mod_op(S[x],v,rx-lx);
            apply_mod_op(op[x],v,1);
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1],S[x*2+2]);
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }
    item calc(int l, int r,int x, int lx, int rx){
        propogate(x,lx,rx);
        //cout << "lx: "<< lx << " rx: "<< rx << " x: "<< x << " op[x]: "<< op[x] << " s[x]: "<< S[x]<< endl;
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        auto q1 = calc(l,r,x*2+1,lx,m);
        auto q2 = calc(l,r,x*2+2,m,rx);
        return calc_op(q1,q2);
    }
    item calc(int l, int r){
        return calc(l,r,0,0,size);
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
            cout << st.calc(l,r)<<"\n";
        }
    }
    return 0;
}
