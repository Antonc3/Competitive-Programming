#include <bits/stdc++.h>
using namespace std;

struct item{
    int l, r, size;
};

struct segtree{
    vector<item> S;
    int size;
    
    item NEUTRAL_ELEMENT = {0,0,0};
    item single(int v){
        return {v,-v,1};
    }
    item merge(item a, item b){
        if(a.size&1){
            return {a.l+b.r,a.r+b.l,a.size+b.size};
        }
        else{
            return {a.l+b.l,a.r+b.r,a.size+b.size};
        }
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,NEUTRAL_ELEMENT);
    }
    void build(vector<int> &a,int x,int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                S[x] = single(a[lx]);
            }
            else{
                S[x] = NEUTRAL_ELEMENT;
            }
            return;
        }
        int m = (rx+lx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            S[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i,v,x*2+1,lx,m);
        }
        else{
            set(i,v,x*2+2,m,rx);
        }
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void set(int i, int v){
        set(i,v,0,0,size);
    }
    item calc(int l, int r,int x, int lx, int rx){
        //cout << "l: " << l << " r: " << r << " x: " << x << " lx: " << lx << " rx: " << rx <<endl;
        if(r <= lx || rx <= l) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return S[x];
        int m =(lx+rx)/2;
        item s0 = calc(l,r,x*2+1,lx,m);
        item s1 = calc(l,r,x*2+2,m,rx);
        return merge(s0,s1);
    }
    item calc(int l, int r){
        return calc(l,r,0,0,size);
    }
};

int main(){
    int n,m;
    cin >> n  ;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    segtree st;
    st.init(n+1);
    st.build(arr);
    cin >> m;
    while(m--){
        int op;
        cin >> op;
        if(op==0){
            int i,v;
            cin >> i >> v;
            i--;
            st.set(i,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            l--; r--;
            item cur = st.calc(l,r+1);
            //cout << "cur size: " << cur.size << endl;
            cout << cur.l<<endl;
        }
    }

}
