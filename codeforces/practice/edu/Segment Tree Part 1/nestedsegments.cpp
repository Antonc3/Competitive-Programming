#include <bits/stdc++.h>
using namespace std;

struct item{
    int v;
};

struct segtree{
    vector<item> S;
    int size;
    
    item NEUTRAL_ELEMENT = {0};
    item single(int v){
        return {v};
    }
    item merge(item a, item b){
        return {a.v+b.v};
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
    int n;
    cin >> n;
    vector<int> cnt(n,-1);
    vector<int> a(2*n);
    for(int i =0; i < 2*n; i++){
        cin >> a[i];
        a[i]--;
    }
    //cout << "WTF\n";
    segtree st;
    st.init(2*n);
    vector<int> ans(n);
    for(int i = 0; i < 2*n; i++){
        if(cnt[a[i]] == -1){
            cnt[a[i]] = i;
        }
        else{
            ans[a[i]] = st.calc(cnt[a[i]],i).v;
            st.set(cnt[a[i]],1);
        }
        
    }
    for(int i : ans) cout << i << " ";
    cout << "\n";
}
