#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e9;
struct segtree{
    //min, max
    vector<int> S;
    int size;
    
    int merge(int a, int b){
        return min(a,b);
    }
    void init(int n){
        size = 1;
        while( size < n) size*=2;
        S.resize(size*2,INF);
    }
    void update(int i, int v, int x, int lx, int rx){
        if(rx-lx == 1){
            S[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if( i < m){
            update(i,v,x*2+1,lx,m);
        }
        else{
            update(i,v,x*2+2,m,rx);
        }
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void update(int i, int v){
        update(i,v,0,0,size);
    }
    int query(int l, int r,int x, int lx, int rx){
        if(r <= lx || rx <= l) return INF;
        if(l <=lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        int s1 = query(l,r,x*2+1,lx,m);
        int s2 = query(l,r,x*2+2,m,rx);
        return merge(s1,s2);
    }
    int query(int l, int r){
        return query(l,r,0,0,size);
    }

};

struct segtree2{
    //max, min
    vector<pii> S;
    int size;
    vector<int> a; 
    pii merge(pii x, pii y){
        pii res;
        if(x.first == INF) return y;
        if(y.first == INF) return x;
        if(a[x.first] > a[y.first]) res.first = x.first;
        else res.first = y.first;
        if(a[x.second] < a[y.second]) res.second = x.second;
        else res.second = y.second;
        return res;
    }
    void init(int n){
        size = 1;
        while( size < n) size*=2;
        S.resize(size*2,{INF,INF});
    }
    void build(int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                S[x]={lx,lx};
            }
            return;
        }
        int m = (lx+rx)/2;
        build(x*2+1,lx,m);
        build(x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void build(vector<int> &arr){
        a = vector<int>(arr);
        build(0,0,size);
    }
    pii query(int l, int r,int x, int lx, int rx){
        if(r <= lx || rx <= l) return {INF,INF};
        if(l <=lx && rx <= r){
            return S[x];
        }
        int m = (lx+rx)/2;
        auto s1 = query(l,r,x*2+1,lx,m);
        auto s2 = query(l,r,x*2+2,m,rx);
        return merge(s1,s2);
    }
    pii query(int l, int r){
        return query(l,r,0,0,size);
    }

};
void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    //find first index larger than a[i];

    vi nxtlarger(n);
    vi nxtsmaller(n);
    segtree st;
    st.init(n+1);
    for(int i = n-1; i >= 0; i--){
        int cur = a[i];
        int firstsmaller = st.query(0,cur);
        int firstlarger = st.query(cur,n+1);
        nxtlarger[i] = firstlarger;
        nxtsmaller[i] = firstsmaller;
        st.update(cur,i);
    }
    int cnt = 0;
    segtree2 st2;

    st2.init(n+1);
    st2.build(a);
    for(int i =0; i < n-1;){
        if(a[i] > a[i+1]){
            //find the next one larger than the current i
            int r = min(n,nxtlarger[i]);
            auto bounds = st2.query(i,r);
            i = bounds.second;
        }
        else{
            int r = min(n,nxtsmaller[i]);
            auto bounds = st2.query(i,r);
            i = bounds.first;
        }
        cnt++;
        //int best = i+1;
        //int j = i+1;
        //if(a[i] > a[i+1]){
        //    while(j < n && a[j] < a[i]){
        //        if(a[best] > a[j]){
        //            best = j;
        //        }
        //        j++;
        //    }
        //}
        //else{
        //    while(j < n && a[j] > a[i]){
        //        if(a[best] < a[j]){
        //            best = j;
        //        }
        //        j++;
        //    }
        //}
        //i = best-1;
        //cnt++;
    }
    cout << cnt << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
