#include <bits/stdc++.h>
using namespace std;

const bool DEBUG = false;
struct item{
    int v;
};
struct segtree{
    int size;
    vector<item> S;
    item NEUTRAL_ELEMENT = {0};

    item single(int v){
        return {v};
    }
    item merge(item a, item b){
        return {a.v+b.v};
    }
    void init(int n){
        size=1;
        while(size < n) size*=2;
        S.assign(2*size,NEUTRAL_ELEMENT);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx == 1){
            if(lx < a.size()){
                S[x] = single(a[lx]);
            }
            else{
                S[x] = NEUTRAL_ELEMENT;
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
    void set(int i, int v,int x, int lx, int rx){
        if(DEBUG) cout << i << " " << "x: " << x << " lx " << lx << " rx " << rx <<endl;
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
    
    item calc(int l, int r, int x, int lx, int rx){
        //cout << "x:" << x<< " lx " << lx << " rx " << endl;
        if(r <= lx || l >= rx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item s1 = calc(l,r,x*2+1,lx,m);
        item s2 = calc(l,r,x*2+2,m,rx);
        return merge(s1,s2);
    }
    item calc(int l, int r){
        return calc(l,r,0,0,size);
    }
    int find(int k,int x, int lx, int rx){
        //cout << "k " << k << " x " << x << " lx " << lx << " rx " << rx << endl;
        if(rx-lx == 1){
            return lx;
        }
        int m = (lx+rx)/2;
        item sl = S[2*x+1];
        //cout << "SL V: " << sl.v << endl;
        if(k <= sl.v){
            return find(k,x*2+1,lx,m);
        }
        else{
            return find(k-sl.v,x*2+2,m,rx);
        }
    }
    int find(int k){
        return find(k,0,0,size);
    }
};

int main(){
    int n;
    cin >> n;
    segtree st;
    st.init(n);
    vector<int> ans(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> initial(n,1);
    st.build(initial);
    for(int i = n-1; i >= 0; i--){
        //cout << "i+1-a[i] " <<i+1-a[i] << " i " << i << endl;
        ans[i] = st.find(i+1-a[i]);     
        st.set(ans[i],0);
    }
    for(int i : ans)  cout << i+1 << " ";
    cout << "\n";
}
