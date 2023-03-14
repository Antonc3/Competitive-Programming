#include <bits/stdc++.h>
using namespace std;


struct segtree{
    vector<int> S;
    vector<int> op;
    int size;
    int NEUTRAL_ELEMENT = 1e9;
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        S.resize(2*size,NEUTRAL_ELEMENT);
        op.resize(2*size,0);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                S[x] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = min(S[x*2+1],S[x*2+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        if(op[x] == 0) return;
        S[x*2+1] += op[x];
        S[x*2+2] += op[x];
        op[x*2+1] += op[x];
        op[x*2+2] += op[x];
        op[x] = 0;
    }
    void modify(int l, int r, int v, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            S[x] += v;
            op[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        modify(l,r,v,x*2+1,lx,m);
        modify(l,r,v,x*2+2,m,rx);
        S[x] = min(S[x*2+1],S[x*2+2]);
    }

    void modify(int l, int r, int v){
        modify(l,r,v,0,0,size);
    }

    int getmin(int x, int lx, int rx){
        propogate(x,lx,rx);
        if(S[x] >= 0) return -1;
        if(rx-lx==1) return lx;
        int m = (lx+rx)/2;
        int left = getmin(x*2+1,lx,m);
        if(left == -1) return getmin(x*2+2,m,rx);
        return left;
    }
    int getmin(){
        return getmin(0,0,size);
    }
    
};
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i <= n; i++) a[i] = i;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    segtree st;
    st.init(n+1);
    st.build(a);
    
    long long total = 0;
    long long cnt = 0;
    for(int i = 0; i < n; i++){

        int cur = arr[i];
        cnt++;
        total+=cur;
        st.modify(cur,n+1,-1);
        int curmin = st.getmin();
        if(curmin != -1){
            st.modify(curmin,n+1,1);
            cnt--;
            total-=curmin;
        }
        cout << total-1ll*cnt*(cnt+1)/2 << " ";
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        
    }
}

