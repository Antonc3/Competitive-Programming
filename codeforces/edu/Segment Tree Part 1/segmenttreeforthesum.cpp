#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree{
    vector<ll> S;
    int size;
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        S = vector<ll>(2*size,0ll);
    }
    void build(vector<int> &a,int x, int lx, int rx){
        if(rx-lx<= 1){
            if(lx < a.size()){
                S[x] = a[lx];
            }
            return;
        }
        int mid = (lx+rx)/2;
        build(a,x*2+1,lx,mid);
        build(a,x*2+2,mid,rx);
        S[x] = S[x*2+1]+S[x*2+2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);

    }
    void set(int i, int v,int x, int lx, int rx){
        if( rx-lx <= 1) {
            S[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m){
            set(i,v,2*x+1,lx,m);
        }
        else{
            set(i,v,2*x+2,m,rx);
        }
        S[x] = S[2*x+1] + S[2*x+2];
    }
    void set(int i, int v){
        set(i,v,0,0,size);
    }
    
    ll sum(int l, int r, int x, int lx, int rx){
        if(r <= lx || l >= rx) return 0;
        if(lx >= l && rx <= r) return S[x];
        int mid = (lx+rx)/2; 
        ll left = sum(l,r,2*x+1,lx,mid);
        ll right = sum(l,r,2*x+2,mid,rx);
        //cout << "left: " << left << " right: " << right << endl;
        return left+right;
    }

    ll sum(int l, int r){
        //cout << l << " " << r << endl;
        return sum(l,r,0,0,size);
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i =0 ; i < n; i++){
        cin >> a[i]; 
    }
    st.build(a);
    while(m--){
        int op;
        cin >> op;
        //cout << "OP: " << op << endl;
        if(op==1){
            int a,b;
            cin >> a >> b;
            st.set(a,b);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << st.sum(l,r) << "\n";
        }
    }
}
