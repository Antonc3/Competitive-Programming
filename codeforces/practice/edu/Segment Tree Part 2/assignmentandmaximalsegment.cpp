#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item{
    ll val, pref, suff, sum;
};
struct segtree{
    vector<item> S;
    vector<ll> op;

    ll NO_OP = LLONG_MAX;
    item NEUTRAL_ELEMENT = {0,0,0,0};

    int size;
    item calc_op(item a, item b){
        return {
            max({a.val,b.val,a.suff+b.pref}),
            max(a.pref,a.sum+b.pref),
            max(b.suff,a.suff+b.sum),
            a.sum+b.sum
        };
    }
    item modify_op(item a,ll b,ll len){
        if(b < 0){
            return {
                0,
                0,
                0,
                b*len
            };
        }
        return {
            b*len,
            b*len,
            b*len,
            b*len
        };
    }
    void apply_modify_op(item &a, ll b, ll len){
        a = modify_op(a,b,len);
    }

    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        if(op[x] == NO_OP) return;
        int m = (rx+lx)/2;
        apply_modify_op(S[x*2+1],op[x],m-lx);
        op[x*2+1] = op[x];
        apply_modify_op(S[x*2+2],op[x],rx-m);
        op[x*2+2] = op[x];
        op[x] = NO_OP;
    }

    void init(int n){
        size = 1;
        while(size<n) size*=2;
        S.resize(2*size,NEUTRAL_ELEMENT);
        op.resize(2*size,NO_OP);
    }

    void modify(int l, int r, int v,int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            op[x] = v;
            apply_modify_op(S[x],v,rx-lx);
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        //cout << "lx: "<< lx << " rx: " << rx << " S[x*2+1]: " << S[x*2+1].val << " S[x*2+2]: " << S[x*2+2].val << endl;
        S[x] = calc_op(S[x*2+1],S[x*2+2]);
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }
    item calc(int l,int r,int x,int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item s1 = calc(l,r,x*2+1,lx,m);
        item s2 = calc(l,r,x*2+2,m,rx);
        return calc_op(s1,s2);
    }
    item calc(int l,int r){
        return calc(l,r,0,0,size);
    }
};

int main(){
    int n,m;
    cin >> n >>m;
    segtree st;
    st.init(n);
    while(m--){
        int l,r,v;
        cin >> l >> r >> v;
        st.modify(l,r,v);
        cout << st.calc(0,n).val<<"\n";
    }
}
