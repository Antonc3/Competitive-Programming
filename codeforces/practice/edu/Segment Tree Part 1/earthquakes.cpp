#include <bits/stdc++.h>
using namespace std;

struct item{
    int val, ind;
};
struct segtree{
    vector<item> S;
    int size;

    item NEUTRAL_ELEMENT = {(int) 2e9,-1};
    item single(int v, int i){
        return {v,i};
    }
    item merge(item a, item b){
        if(a.val > b.val) return b; 
        return a;
    }
    void init(int n){
        size =1;
        while(n>size) size*=2;
        S.resize(2*size,NEUTRAL_ELEMENT);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            S[x] = single(v,i);
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
        //cout << "l: " << lx << " rx: " << rx << " X: " << x <<endl;
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item rl = calc(l,r,x*2+1,lx,m);
        item rr = calc(l,r,x*2+2,m,rx);
        return merge(rl,rr);
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
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }
        else{
            int l,r,v;
            cin >> l >> r >> v;
            item cur = st.calc(l,r);
            int cnt = 0;
            while(cur.val <= v){
                st.set(cur.ind,2e9);
                cnt++;
                cur = st.calc(l,r);
            }
            cout << cnt << endl;
        }
    }
}
