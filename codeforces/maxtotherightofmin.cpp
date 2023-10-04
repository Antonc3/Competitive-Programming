#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006
typedef long long ll;
struct item{
    int mn, mx;
};
struct segtree{
    vector<item> S;
    item NEUTRAL_ELEMENT = {MAXN,-MAXN};
    int size;
    item merge(item a, item b){
        item res;
        res.mn = min(a.mn,b.mn);
        res.mx = max(a.mx,b.mx);
        return res;
    }
    void init(int n){
        while(size < n){
            size*=2;
        }
        S.resize(size);
    }
    void build(int n, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < n){
                item d;
                d.mn = a[x];
                d.mx = a[x];
                S[x] = d;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(n,x*2+1,lx,m);
        build(n,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }

    item query(int l, int r,int x, int lx, int rx){
        if(rx <= l || r <= lx) return NEUTRAL_ELEMENT;
        if(l <= lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        auto q1 = query(l,r,x*2+1,lx,m);
        auto q2 = query(l,r,x*2+2,m,rx);
        return merge(q1,q2);
    }
    item query(int l, int r){
        return query(l,r,0,0,size);
    }
};
int a[MAXN];
int pos[MAXN];
segtree st;

ll recurse(int l, int r){
    if(r==l) return 0;
    if(r-l == 1) return a[r] > a[l];
    item res = st.query(l,r+1);
    int mnpos = pos[res.mn];
    int mxpos = pos[res.mx];
    ll ans = 0;
    if(mxpos > mnpos){
        ans+=2*(mxpos-mnpos-1);
        ll lcnt = (mnpos-l+1);
        ll rcnt = mxpos-r+1;
        ans+= (lcnt*rcnt);
    }
    int tmpr = mxpos+1;
    int tmpl = mxpos-1;
    int curmin = a[tmpl];
    while(tmpl >= l){
        curmin = min(curmin,a[tmpl]);
        while(tmpr <= r && a[tmpr] > curmin){
            tmpr++;
        }
        ans+=(tmpr-mxpos);
        tmpl--;
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
        pos[a[i]] = i;
    } 
}

int main(){
    solve();
}