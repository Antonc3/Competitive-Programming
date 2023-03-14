#include <bits/stdc++.h>
using namespace std;
#define MAXNUM  45
typedef long long ll;

struct item{
    vector<int> cnt;
    ll numdif;
    item(){
        cnt.assign(MAXNUM,0);
        numdif = 0;
    }
};

struct segtree{
    vector<item> S;
    int size;

    item NEUTRAL_ELEMNT = item();

    item single(int v){
        item res = item();
        res.cnt[v]=1;
        res.numdif = 1;
        return res;
    }
    item merge(item a, item b){
        item res = item();
        for(int i = 0; i < MAXNUM; i++){
            res.cnt[i] = a.cnt[i] + b.cnt[i];
            res.numdif += (res.cnt[i]>0);
        }
        return res;
    }
    void init(int n){
        size = 1;
        while(size <n){
            size*=2;
        }
        S.assign(2*size,NEUTRAL_ELEMNT);
    }
    void build(vector<int> &a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                S[x] = single(a[lx]);
            }
            else{
                S[x] = NEUTRAL_ELEMNT;
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
    item calc(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) return NEUTRAL_ELEMNT;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item r0 = calc(l,r,x*2+1,lx,m);
        item r1 = calc(l,r,x*2+2,m,rx);
        return merge(r0,r1);
    }
    item calc(int l, int r){
        //cout << "INV COUNT: " <<S[0].invCnt<<endl;
        return calc(l,r,0,0,size);
    }
};



int main(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    segtree st;
    st.init(n);
    st.build(arr);
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int l,r;
            cin >> l >> r;
            l--;
            cout << st.calc(l,r).numdif<<endl;
        }
        else{
            int i,v;
            cin >> i >>v;
            st.set(i-1,v);
        }
    }
}
