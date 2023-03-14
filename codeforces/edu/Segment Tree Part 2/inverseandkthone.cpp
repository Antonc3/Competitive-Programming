#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item{
    ll zerocnt, onecnt;
};

struct segtree{
    vector<item> S;
    vector<int> op;
    
    int size;
    item NEUTRAL_ELEMENT = {0,0};

    item calc_op(item a, item b){
        return {a.zerocnt+b.zerocnt,a.onecnt+b.onecnt};
    }
    item modify_op(item a, int oper){
        if(oper) return {a.onecnt,a.zerocnt};
        return a;
    }
    void apply_modify_op(item &a, int oper){
        a = modify_op(a,oper);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        if(op[x]%2==0) return;
        apply_modify_op(S[x*2+1], 1);
        op[x*2+1]++;
        apply_modify_op(S[x*2+2], 1);
        op[x*2+2]++;
        op[x] = 0;
    }
    
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,NEUTRAL_ELEMENT);
        op.resize(size*2,0);
        build(n,0,0,size);
    }
    void build(int n,int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < n){
                S[x] = {1,0};
            }
            return;
        }
        int m = (lx+rx)/2;
        build(n,x*2+1,lx,m);
        build(n,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1],S[x*2+2]);
    }

    void modify(int l , int r, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_modify_op(S[x], 1);
            op[x] = 1;
            //cout << "x: "<< x << " lx: "<< lx << " rx: " << rx  << endl;
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,x*2+1,lx,m);
        modify(l,r,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1], S[x*2+2]);
    }
    void modify(int l, int r){
        modify(l,r,0,0,size);
    }
    int calc(int k, int x, int lx, int rx){
        //cout << "k: "<< k << " x: "<< x <<" lx: " << lx << " rx: "<< rx << endl;
        propogate(x, lx, rx);
        if(rx-lx == 1) return lx;
        int m = (lx+rx)/2;
        int leftones = S[x*2+1].onecnt;
        //cout << "leftones: "<< leftones << endl;
        if(k-leftones <= 0){
            return calc(k,x*2+1,lx,m);
        }
        else{
            return calc(k-leftones,x*2+2,m,rx);
        }
    }
    int calc(int k){
        return calc(k,0,0,size);
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
            int l,r;
            cin >> l >> r;
            st.modify(l,r);
        }
        else{
            int k;
            cin >> k;
            cout << st.calc(k+1)<<"\n";
        }
    }
}
