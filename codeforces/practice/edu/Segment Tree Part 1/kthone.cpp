#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef int item;
//struct item{
//    int sum;
//};
struct segtree{
    vector<item> S;
    int size;

    item neutral_element = 0;
    item merge(item a, item b){
        return a+b;
    }
    item single(int v){
        return v;
    }
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size);
    }
    void build(vector<int> &a,int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx < a.size()){
                S[x] = single(a[lx]);
            }
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
    int search(int k, int x, int lx, int rx){
        if(rx-lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        item sl = S[2*x+1];
        if(k < sl){
            return search(k,x*2+1,lx,m);
        }
        else{
            return search(k-sl,x*2+2,m,rx);
        }
    }
    int search(int ind){
        return search(ind,0,0,size);
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
    while(m--){
        int op, v;
        cin >> op >> v;
        if(op == 1){
            a[v] = 1-a[v];
            st.set(v,a[v]);
        }
        else{
            cout << st.search(v)<<"\n";
        }
    }
}
