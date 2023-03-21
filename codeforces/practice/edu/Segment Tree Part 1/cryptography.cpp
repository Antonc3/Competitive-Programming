#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int r;
struct item{
    int a,b,c,d;
};

struct segtree{
    vector<item> S;
    int size;
    
    item NEUTRAL_ELEMENT = {1,0,0,1};
    item single(item v){
        return v;
    }
    item merge(item a, item b){
        return {(a.a*b.a+a.b*b.c)%r,
            (a.a*b.b+a.b*b.d)%r,
            (a.c*b.a+a.d*b.c)%r,
            (a.c*b.b+a.d*b.d)%r};
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,NEUTRAL_ELEMENT);
    }
    void build(vector<item> &a,int x,int lx, int rx){
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
    void build(vector<item> &a){
        build(a,0,0,size);
    }
    void set(int i, item v, int x, int lx, int rx){
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
    void set(int i,item v){
        set(i,v,0,0,size);
    }
    item calc(int l, int r,int x, int lx, int rx){
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
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin >>r >> n >>m;
    segtree st;
    st.init(n);
    for(int i =0; i < n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        st.set(i,{a,b,c,d});
    }
    while(m--){
        int l,r;
        cin >> l >> r;
        l--;
        item cur = st.calc(l,r); 
        cout << cur.a << " " << cur.b << "\n"<<cur.c << " " << cur.d<<"\n\n";
    }
}
