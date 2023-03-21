#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
const bool DEBUG = false;

typedef ll item;

struct segtree{
    vector<item> S;
    vector<item> assignop;
    vector<item> addop;
    
    int size;

    item NEUTRAL_ELEMENT = 0;
    item ADD_NO_OP = 0;
    item ASSIGN_NO_OP = -1;
    item calc_op(item a, item b){
        return a+b;
    }

    item assign_op(item a, item oper, int len){
        return oper*len;
    }

    item add_op(item a, item oper, int len){
        return a+oper*len;
    }

    void apply_assign_op(item &a, item oper, int len){
        a = assign_op(a,oper,len);
    }

    void apply_add_op(item &a, item oper, int len){
        a = add_op(a,oper,len);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        int m =(lx+rx)/2;
        if(assignop[x] != ASSIGN_NO_OP){
            apply_assign_op(S[x*2+1], assignop[x],m-lx);
            apply_assign_op(S[x*2+2], assignop[x],rx-m);
            assignop[x*2+1] = assignop[x];
            assignop[x*2+2] = assignop[x];
            addop[x*2+1] = ADD_NO_OP;
            addop[x*2+2] = ADD_NO_OP;
            assignop[x] = ASSIGN_NO_OP;
        }
        if(addop[x] != ADD_NO_OP){
            apply_add_op(S[x*2+1], addop[x],m-lx);
            apply_add_op(S[x*2+2], addop[x],rx-m);
            addop[x*2+1] += addop[x];
            addop[x*2+2] += addop[x];
            addop[x] = ADD_NO_OP;
        }
    }
    
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,0);
        addop.resize(2*size,0);
        assignop.resize(2*size,0);
    }

    void assign(int l , int r, int v, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_assign_op(S[x],v,rx-lx);
            addop[x] = 0;
            assignop[x] = v;
            //if(DEBUG) cout << "x: "<< x << " lx: "<< lx << " rx: " << rx  << endl;
            return;
        }
        int m = (lx+rx)/2;
        assign(l,r,v,x*2+1,lx,m);
        assign(l,r,v,x*2+2,m,rx);
        S[x] = calc_op(S[x*2+1], S[x*2+2]);
    }
    void assign(int l, int r, int v){
        assign(l,r,v,0,0,size);
    }
    void add(int l , int r, int v, int x, int lx, int rx){
        if(DEBUG) cout << "before! lx: "<< lx << " rx: "<< rx <<" lc: "<< S[x*2+1] << " rc: "<< S[x*2+2]<<endl;
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            apply_add_op(S[x],v,rx-lx);
            addop[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        add(l,r,v,x*2+1,lx,m);
        add(l,r,v,x*2+2,m,rx);
        if(DEBUG) cout << "after! lx: "<< lx << " rx: "<< rx <<" lc: "<< S[x*2+1] << " rc: "<< S[x*2+2]<<endl;
        S[x] = calc_op(S[x*2+1], S[x*2+2]);
    }
    void add(int l, int r, int v){
        add(l,r,v,0,0,size);
    }
    item calc(int l,int r, int x, int lx, int rx){
        if(DEBUG) cout << "l: "<< l << " r: "<< r <<" x: "<< x <<" lx: " << lx << " rx: "<< rx << " S[x]: "<< S[x]<<endl;
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r) return S[x];
        int m = (lx+rx)/2;
        item s1 = calc(l,r,x*2+1,lx,m);
        item s2 = calc(l,r,x*2+2,m,rx);
        return calc_op(s1,s2);
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
            int l,r,v;
            cin >> l >> r >> v;
            st.assign(l,r,v);
        }
        else if(op==2){
            int l,r,v;
            cin >> l >> r >> v;
            st.add(l,r,v);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << st.calc(l,r)<<"\n";
        }
    }
}
