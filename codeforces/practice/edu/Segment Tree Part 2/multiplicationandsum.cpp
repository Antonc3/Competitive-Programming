#include <bits/stdc++.h>
using namespace std;

typedef long long item;

const bool DEBUG = false;
item M = 1e9+7;

item fastpow(item i, item e){
    if(e==0) return 1;
    if(e&1){
        return i*fastpow(i*i%M,e/2)%M;
    }
    else{
        return fastpow(i*i%M,e/2)%M;
    }
}

struct segtree{
    int size;
    vector<item> S;
    vector<item> op;

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,0);
        op.resize(2*size,1);
    }

    void build(vector<int> &a,int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                S[x] = a[lx];
                op[x] = 1;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = S[x*2+1]+S[x*2+2];
        op[x] = (op[x*2+1]*op[x*2+2])%M;
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    
    void multiply(int l, int r, item v, int x, int lx, int rx){
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            op[x]=op[x]*v%M;
            if(DEBUG) cout << "before: "<< S[x]<<endl;
            S[x]=S[x]*v%M;
            if(DEBUG) cout << "S[x] " << S[x] << " fastpow: " << fastpow(v,rx-lx) << endl;
            return;
        }
        int m = (lx+rx)/2;
        multiply(l,r,v,x*2+1,lx,m);
        multiply(l,r,v,x*2+2,m,rx);
        S[x] = ((S[x*2+1]+S[x*2+2]) * op[x]) % M;
    }

    void multiply(int l, int r, int v){
        multiply(l,r,v,0,0,size);
    }

    item calc(int l, int r,int x, int lx, int rx){
        if(rx <= l || r <= lx){
            return 0ll;
        }
        if(l <= lx && rx <= r){
            return S[x];
        }
        int m = (rx+lx)/2;
        item s1 = calc(l,r,x*2+1,lx,m);
        item s2 = calc(l,r,x*2+2,m,rx);
        int numElements = (min({rx-lx,r-lx,rx-l,r-l}));
        if(DEBUG) cout << "l: "<< l << " r: " << r << " lx: "<< lx << " rx: " << rx <<endl;
        if(DEBUG) cout << "numelements: " << numElements<<endl;
        if(DEBUG) cout << "s1: "<< s1 << " s2: " << s2 << endl;
        if(DEBUG) cout << "op[x]: "<< op[x] << " fastpow: " << fastpow(op[x],numElements)<<endl;
        if(DEBUG) cout << endl;
        return ((s1+s2)*op[x])%M;
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
    vector<int> start(n,1);
    st.build(start);
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l,r,v;
            cin >> l >> r >> v;
            st.multiply(l,r,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << st.calc(l,r)<<endl;
        }
    }
}
