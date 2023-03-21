#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

struct segtree{
    vector<pii> S;
    int size;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.assign(2*size,{2e9,0});
    }
    pii merge(pii a, pii b){
        if(a.F == b.F) return {a.F, a.S+b.S};
        if(a.F > b.F) return {b.F, b.S};
        return a;
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                S[x] = {a[lx],1};
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
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx == 1){
            S[x] = {v,1};
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
    pii get(int l, int r, int x, int lx, int rx){
        if(r <= lx || l >= rx) return {2e9,0};
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        pii left = get(l,r,x*2+1,lx,m);
        pii right = get(l,r,x*2+2,m,rx);
        return merge(left,right);
    }
    pii get(int l, int r){
        return get(l,r,0,0,size);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    segtree st;
    st.init(n);
    st.build(a);
    while(m--){
        int op;
        cin >> op;
        int a,b;
        cin >> a >> b;
        if(op==1){
            st.set(a,b);
        }
        else{
            pii result = st.get(a,b);
            cout << result.F << " " << result.S<<endl;
        }
    }
}
