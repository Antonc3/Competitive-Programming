#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef ll item;


struct segtree{
    vector<item> S;
    vector<item> a_;
    vector<item> d_;
    
    int size;
    item NEUTRAL_ELEMENT = 0;

    item NO_OP = 0;
    item calc_op(item a, item b){
        return a+b;
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,0);
        a_.assign(2*size,NO_OP);
        d_.assign(2*size,NO_OP);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        int m = (lx+rx)/2;
        S[x*2+1] += a_[x];
        S[x*2+2] += a_[x]+d_[x]*(m-lx);
        a_[x*2+1] += a_[x];
        a_[x*2+2] += a_[x]+d_[x]*(m-lx);
        d_[x*2+1] += d_[x];
        d_[x*2+2] += d_[x];
        d_[x] = 0;
        a_[x] = 0;
    }
    void modify(int l, int r, item a, int d, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            S[x] += a;
            a_[x] +=a;
            d_[x] += d;
            return;
        }
        int m = (lx+rx)/2;
        int lmax = max(l,lx);
        modify(l,r,a,d,x*2+1,lx,m);
        modify(l,r,a+max(0ll,1ll*d*(m-lmax)),d,x*2+2,m,rx);
    }
    void modify(int l, int r, item a, int d){
        modify(l,r,a,d,0,0,size);
    }
    item get(int i, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx-lx==1) return S[x];
        int m = (lx+rx)/2;
        if(i < m){
            return get(i,x*2+1,lx,m);
        }
        else{
            return get(i,x*2+2,m,rx);
        }
    }

    item get(int i){
        return get(i,0,0,size);
    }
};


int main(){
    int n,m;
    cin >> n >> m;
    segtree st;
    st.init(n+1);

    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l,r,a,d;
            cin >> l >> r >> a >> d;
            st.modify(l,r+1,a,d);
        }
        else{
            int k;
            cin >> k;
            cout << st.get(k)<<"\n";
        }
    }
}
