#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//struct item{
//    ll mseg, pref, suf, sum;
//};
typedef int item;
struct segtree{
    vector<item> S;
    int size;
    item neutral_element = 0;
    item merge(item a, item b){
        return max(a,b);
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
            else{
                S[x] = neutral_element;
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
    int find(int v, int l,int x, int lx, int rx){
        //cout << "x: " << x << " lx: " << lx << " rx: " << rx <<endl;
        if(S[x] < v || rx <= l) return -1;
        if(rx-lx == 1){
            if(lx < l) return -1;
            return lx;
        }
        int m = (lx+rx)/2;
        if(S[x*2+1] >= v){
            int s1 = find(v,l,x*2+1,lx,m);
            return (s1==-1) ? find(v,l,x*2+2,m,rx) : s1;
        }
        else{
            return find(v,l,x*2+2,m,rx);
        }
    }
    int find(int v,int l){
        if(calc(l,size) < v) return -1;
        return find(v,l,0,0,size);
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
        int op;
        cin >> op;
        if(op==1){
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }
        else{
            int x, l;
            cin >> x>>l;
            cout << st.find(x,l)<<"\n";
        }
    }
}
