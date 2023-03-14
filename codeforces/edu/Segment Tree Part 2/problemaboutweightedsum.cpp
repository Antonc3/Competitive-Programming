#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;
const bool DEBUG = false;

typedef long long item;
struct segtree{
    vector<item> sums;
    vector<item> multsums;
    vector<item> op;

    int size;
    item NEUTRAL_ELEMENT = 0;
    item NO_OP = 0;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        sums.resize(2*size,NEUTRAL_ELEMENT);
        multsums.resize(2*size,NEUTRAL_ELEMENT);
        op.resize(2*size,NO_OP);
    }

    item lxrxsum(int lx, int rx){
        return ((1ll*rx*(rx-1))/2)-((1ll*lx*(lx-1))/2);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                sums[x] = a[lx];
                multsums[x] = 1ll*a[lx]*lx;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        sums[x] = sums[x*2+1]+sums[x*2+2];
        multsums[x] = multsums[x*2+1]+multsums[x*2+2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void propogate(int x,int lx, int rx){
        if(rx-lx==1) return;
        int m = (lx+rx)/2;
        sums[x*2+1] += 1ll*(m-lx)*op[x];
        sums[x*2+2] += 1ll*(rx-m)*op[x];
        multsums[x*2+1] += lxrxsum(lx,m)*op[x];
        multsums[x*2+2] += lxrxsum(m,rx)*op[x];
        op[x*2+1] += op[x];
        op[x*2+2] += op[x];
        op[x] = NO_OP;
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        if(DEBUG) cout << "x: " << x << " lx: " << lx << " rx: " << rx << endl;
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            if(DEBUG) cout << "lxrxsum: " << lxrxsum(lx, rx)<< endl;
            multsums[x] += lxrxsum(lx, rx)*v;
            sums[x] += 1ll*(rx-lx)*v; 
            if(DEBUG) cout << "sums[x]: " << sums[x] << " multsums: " << multsums[x] << endl;
            op[x] += v;
            propogate(x,lx,rx);
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        sums[x] = sums[x*2+1]+sums[x*2+2];
        multsums[x] = multsums[x*2+1]+multsums[x*2+2];
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }
    item calc_sums(int l, int r, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return sums[x]; 
        int m = (lx+rx)/2;
        item s1 = calc_sums(l,r,x*2+1,lx,m);
        item s2 = calc_sums(l,r,x*2+2,m,rx);
        return s1+s2;
    }
    item calc_mult_sums(int l, int r, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return multsums[x];
        int m = (lx+rx)/2;
        item s1 = calc_mult_sums(l,r,x*2+1,lx,m);
        item s2 = calc_mult_sums(l,r,x*2+2,m,rx);
        return s1+s2;
    }
    item calc(int l, int r){
        return calc_mult_sums(l,r,0,0,size)-calc_sums(l,r,0,0,size)*(l-1);
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a;
    a.push_back(0);
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        a.push_back(v);
    }
    segtree st;
    st.init(n+5);
    st.build(a);
    
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int l,r,d;
            cin >> l >> r >> d;
            st.modify(l,r+1,d);
        }
        else{
            int l,r;
            cin >> l >>r;
            cout << st.calc(l,r+1)<<"\n";
        }
    }
}

