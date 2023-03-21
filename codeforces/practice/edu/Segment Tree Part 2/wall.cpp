#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const bool DEBUG = true;
struct item{
    ll smin,smax,sval;
};
struct segtree{
    //set all buildings to opmax[x] or below that
    vector<ll> opmax;
    //set all buildings to opmin[x] or above that
    vector<ll> opmin;

    int size;
    ll NO_OP = -1;
    ll MAX_NO_OP = LLONG_MAX-1;
    item NEUTRAL_ELEMENT={0,0,0}; 
    void init(int n){
        size = 1;while(size<n)size*=2;
        opmax.resize(2*size,MAX_NO_OP);
        opmin.resize(2*size,NO_OP);
    }

    void propogate(int x, int lx, int rx){
        //when propogate 
        if(rx-lx==1) return;
        if(opmax[x] != MAX_NO_OP){
            //check children operations
            //how do we modify opmin?
            //if opmin[x*2+1] > opmax[x]
            if(opmax[x*2+1] > opmax[x]){
                opmax[2*x+1] = opmax[x];
            }
            if(opmin[x*2+1] > opmax[x]){
                opmin[x*2+1] = opmax[x];
            }
            if(opmax[x*2+2] > opmax[x]){
                opmax[2*x+2] = opmax[x];
            }
            if(opmin[x*2+2] > opmax[x]){
                opmin[x*2+2] = opmax[x];
            }
            opmax[x] = MAX_NO_OP;
        }
        if(opmin[x] != NO_OP){
            //cout << "lx: "<< lx << " rx: " << rx << endl;
            //cout << " opmin[x]: " << opmin[x] << " lc opmin: " << opmin[x*2+1] << " rc opmin: " << opmin[x*2+2] << endl;
            if(opmin[x*2+1] < opmin[x]){
                opmin[x*2+1] = opmin[x];
            }
            if(opmax[x*2+1] < opmin[x]){
                opmax[x*2+1] = opmin[x];
            }
            if(opmin[x*2+2] < opmin[x]){
                opmin[x*2+2] = opmin[x];
            }
            if(opmax[x*2+2] < opmin[x]){
                opmax[x*2+2] = opmin[x];
            }
            opmin[x] = NO_OP;
        }
    }

    void modifymax(int l, int r, int h, int x, int lx, int rx){
        //set everything above h to h
        propogate(x, lx, rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            //cout << "lx: " << lx << " rx: " << rx << " h: " << h << " opmin[x]: " << opmin[x] << " opmax[x]: " << opmax[x]<<endl;
            if(opmin[x] >= h){
                opmin[x] = h;
            }
            if(opmax[x] >= h){
                opmax[x] = h;
            }
            return;
        }
        int m = (lx+rx)/2;
        modifymax(l,r,h,x*2+1,lx,m);
        modifymax(l,r,h,x*2+2,m,rx);
    }

    void modifymax(int l, int r,int h){
        modifymax(l,r,h,0,0,size);
    }
    void modifymin(int l, int r, int h, int x, int lx, int rx){
        //set everything below min to min
        propogate(x, lx, rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            //cout << "lx: " << lx << " rx: " << rx << " h: " << h << " opmin[x]: " << opmin[x] << " opmax[x]: " << opmax[x]<<endl;
            if(opmin[x] <= h){
                opmin[x] = h;
            }
            if(opmax[x] <= h){
                opmax[x] = h;
            }
            //cout << "lx: " << lx << " rx: " << rx << " h: " << h << " opmin[x]: " << opmin[x] << " opmax[x]: " << opmax[x]<<endl;
            return;
        }
        int m = (lx+rx)/2;
        modifymin(l,r,h,x*2+1,lx,m);
        modifymin(l,r,h,x*2+2,m,rx);
    }

    void modifymin(int l, int r,int h){
        modifymin(l,r,h,0,0,size);
    }

    int query(int i, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx-lx==1){
            return (opmin[x] == NO_OP) ? 0 : opmin[x];
        }
        int m = (lx+rx)/2;
        if(i < m){
            return query(i,x*2+1,lx,m);
        }
        else{
            return query(i,x*2+2,m,rx);
        }
    }
    int query(int i){
        return query(i,0, 0, size);
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    segtree st;
    st.init(n+1);
    while(k--){
        int op, l, r, h;
        cin >> op >> l >> r >> h;
        r++;
        if(op==1){
            st.modifymin(l,r,h);
        }
        else{
            st.modifymax(l,r,h);
        }
        //cout << "------------------------\n";    
    }
    for(int i = 0; i < n; i++){
        cout << st.query(i) << "\n";
    }
}
