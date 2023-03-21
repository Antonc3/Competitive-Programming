#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item{
    ll mseg, pref, suf, sum;
};
struct segtree{
    vector<item> S;
    int size;

    item neutral_element = {0ll,0ll,0ll,0ll};
    item merge(item a, item b){
        item res;
        res.mseg = max(a.mseg,max(b.mseg,a.suf+b.pref));
        res.pref = max(a.pref, a.sum+b.pref);
        res.suf = max(b.suf, b.sum+a.suf);
        res.sum = a.sum+b.sum;
        return res;
    }
    item single(int v){
        if(v > 0){
            return {v,v,v,v};
        }
        return {0,0,0,v};
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(4*size,neutral_element);
    }
    void build(vector<int> &a,int x, int lx, int rx){
        if(lx > a.size()) return;
        if(rx-lx == 1){
            S[x] = single(a[lx]);
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i, int v,int x,int lx,int rx){
        if(rx-lx == 1){
            S[x] = single(v);
            return;
        }
        int m = (lx+rx)/2;
        if( i < m){
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
        if(rx <= l || lx >= r) return neutral_element;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item s1 = calc(l,r,x*2+1,lx,m);
        item s2 = calc(l,r,x*2+2,m,rx);
        return merge(s1,s2);
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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    st.build(a);
    cout << st.calc(0,n).mseg<<"\n";
    while(m--){
        int i,v;
        cin >> i >> v;
        st.set(i,v);
        cout << st.calc(0,n).mseg<<"\n";
    }
}
