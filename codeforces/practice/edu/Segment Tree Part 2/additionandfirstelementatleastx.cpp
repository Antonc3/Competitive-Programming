#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

typedef ll item;

struct segtree{
    vector<item> S;
    vector<item> op;
    
    int size;

    item NEUTRAL_ELEMENT = -1;
    item calc_op(item a, item b){
        return max(a,b);
    }
    item modify_op(item a, item oper){
        return a+oper;
    }
    void apply_modify_op(item &a, item oper){
        a = modify_op(a,oper);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        apply_modify_op(S[x*2+1], op[x]);
        op[x*2+1]+=op[x];
        apply_modify_op(S[x*2+2], op[x]);
        op[x*2+2]+=op[x];
        op[x] = 0;
    }
    
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,0);
        op.resize(2*size,0);
        build(n,0,0,size);
    }
    void build(int n,int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < n){
                S[x] = 0;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(n,x*2+1,lx,m);
        build(n,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1],S[x*2+2]);
    }

    void modify(int l , int r, int v, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_modify_op(S[x], v);
            op[x] = v;
            //cout << "x: "<< x << " lx: "<< lx << " rx: " << rx  << endl;
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1], S[x*2+2]);
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }
    int calc(int l,int v, int x, int lx, int rx){
        //cout << "k: "<< k << " x: "<< x <<" lx: " << lx << " rx: "<< rx << endl;
        propogate(x, lx, rx);
        if(rx <= l) return NEUTRAL_ELEMENT;
        if(S[x] < v) return NEUTRAL_ELEMENT;
        if(rx-lx==1) return lx;
        int m = (lx+rx)/2; 
        int left = calc(l,v,x*2+1,lx,m);
        if(left == NEUTRAL_ELEMENT) return calc(l,v,x*2+2,m,rx);
        return left;

    }
    int calc(int l, int v){
        if(S[0] < v) return -1;
        return calc(l,v,0,0,size);
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
            int l,r,v;
            cin >> l >> r >> v;
            st.modify(l,r,v);
        }
        else{
            int x,l;
            cin >> x >> l;
            cout << st.calc(l,x)<<"\n";
        }
    }
}
