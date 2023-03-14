#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const bool DEBUG = false;

struct dsu{
    vector<int> par;
    vector<int> sz;
    vector<pii> rb;
    vector<int> cp;
    int numdisjoint;
    void init(int n){
        par = vector<int>(n);
        sz = vector<int>(n,1);
        numdisjoint = n;
        for(int i =0; i < n; i++){
            par[i] = i;
        }
    }
    int get(int a){
        return (par[a] == a) ? a:get(par[a]);
    }
    void join(int a,int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        if(DEBUG)cout << "JOINING " << a << b << endl;
        rb.push_back({a,b});
        par[a] = b;
        sz[b] +=sz[a];
        numdisjoint--;
    }
    void setcp(){
        cp.push_back(rb.size());
    }
    void rollback(){
        if(cp.empty()) return;
        while(rb.size() > cp.back()){
            pii cur = rb.back();
            rb.pop_back();
            par[cur.F] = cur.F;
            sz[cur.S]-=sz[cur.F];
            numdisjoint++;
        }
        cp.pop_back();
    }
};
struct query{
    bool get;
    int l, r;
    int a,b;
};
dsu d;
vector<int> ans;
void work(int l, int r, vector<query> &queries){
    if(DEBUG)cout << "looking at segment " << l << " to " << r << endl;
    if(l>=r-1){
        d.setcp();
        for(auto q : queries){
            if(!q.get && q.l <= l && l < q.r){
                d.join(q.a,q.b);
            }
        }
        for(int i = 0; i < queries.size(); i++){
            if(queries[i].get && l==queries[i].l){
                if(DEBUG)cout << "AYY!\n";
                for(auto i : d.rb) if(DEBUG)cout << i.F << " " << i.S << endl;
                if(DEBUG)cout << endl;
                ans.push_back(d.numdisjoint);
            }
        }
        d.rollback();
        return;
    }
    d.setcp();
    vector<query> queries2;
    for(auto q : queries){
        if(DEBUG)cout << "q: " << q.get << " l " << q.l << " r " << q.r << " a " << q.a << " b " << q.b << endl;
        if(!q.get && q.l <= l && r < q.r){
            if(DEBUG)cout << "joining: " << q.a << " " <<q.b<<endl;
            d.join(q.a,q.b);
        }
        else if((q.get && l <= q.l && q.r <= r)||
                (!q.get && !(q.r <= l || q.l > r))){
            if(DEBUG)cout << "adding q! \n";
            queries2.push_back(q);
        }
    }
    int mid = (l+r)/2;
    work(l,mid,queries2);
    work(mid,r,queries2);
    d.rollback();
}


int main(){
    int n,m;
    cin >> n >> m;
    d.init(n);
    vector<query> queries;
    map<pii,int> mp;
    for(int i =0; i < m; i++){
        char c;
        cin >> c;
        if(c=='?'){
            queries.push_back({true,i,i,0,0});
        }
        else if(c=='+'){
            int a,b;
            cin >> a >> b;
            a--; b--;
            mp[{a,b}] = i;
        }
        else{
            int a,b;
            cin >> a >> b;
            a--; b--;
            if(mp.count({a,b})){
                queries.push_back({false,mp[{a,b}],i,a,b});
                mp.erase({a,b});
            }
            else{
                queries.push_back({false,mp[{b,a}],i,a,b});
                mp.erase({b,a});
            }
        }
    }
    for(auto i = mp.begin(); i != mp.end(); ++i){
        queries.push_back({false,i->second,m+1,i->F.F,i->F.S});
    }
    if(DEBUG)cout << "queries.size: " << queries.size()<<'\n';
    work(0,m,queries);
    for(int i : ans) cout << i << "\n";
}
