#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct item{
    ll bseg, blen, bstart, bend;   
};
struct segtree{
    vector<item> S;
    vector<int> oper;
    int size;
    
    int NO_OP = -1;
    item NEUTRAL_ELEMENT = {0,0,0,0};
    item single(int v, int lx, int rx){
        if(v==0){
            return {0,0,0,0};
        }
        return {1,rx-lx,1,1};
    }
    item merge(item a, item b){
        if(a.bend && b.bstart){
            return {a.bseg+b.bseg-1,a.blen+b.blen,a.bstart,b.bend};
        }
        return {a.bseg+b.bseg,a.blen+b.blen,a.bstart,b.bend};
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx ==1) return;
        if(oper[x] == NO_OP) return;
        int m = (lx+rx)/2;
        S[x*2+1] = single(oper[x],lx,m);
        S[x*2+2] = single(oper[x],m,rx);
        oper[x*2+1] = oper[x];
        oper[x*2+2] = oper[x];
        oper[x] = NO_OP;
    }
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        S.resize(2*size,{0,0,0,0});
        oper.resize(2*size,NO_OP);
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            S[x] = single(v,lx,rx);
            oper[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size); 
    }
};

#define MAXN 500005
int main(){
    int n;
    cin >> n;
    segtree st;
    st.init(MAXN*2);
    while(n--){
        char col;
        int i, len;
        cin >> col >> i >> len;
        int l = i+MAXN;
        int r = l+len;
        int c = (col=='W') ? 0 : 1;
        st.modify(l,r,c);
        item total = st.S[0];
        cout << total.bseg << " " << total.blen << "\n";
    }
}
