#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second

struct dsu{
    vector<int> par;
    vector<int> sz;
    vector<pair<int,int>> rollback;
    int numdisjoint;
    vector<int> checkpoints;
    void init(int n){
        numdisjoint = n;
        par = vector<int>(n);
        sz = vector<int>(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int get(int a){
        return (par[a] == a) ? a : get(par[a]);
    }
    void join(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        numdisjoint--;
        rollback.push_back({a,b});
        par[a] = b;
        sz[b] += sz[a];
    }
    void setcp(){
        checkpoints.push_back(rollback.size());
    }
    void undojoins(){
        while(rollback.size() > checkpoints.back()){
            numdisjoint++;
            auto cur = rollback.back();
            rollback.pop_back();
            int a = cur.F;
            int b = cur.S;
            par[a] = a;
            sz[b]-=sz[a];
        }
        checkpoints.pop_back();
    }

};
typedef pair<int,int> pii;
#define F first
#define S second

bool compareSecond(pair<pii,int> a,pair<pii,int> b){
    return a.F.S < b.F.S;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<pii> edges;
    for(int i =0; i < m; i++){
        int a,b;
        cin >> a >> b;
        edges.push_back({--a,--b});
    }
    int q;
    cin >> q;
    vector<pair<pii,int>> queries;
    for(int i =0; i < q; i++){
        int l,r;
        cin >> l >> r;
        queries.push_back({{--l,--r},i});
    }
    sort(queries.begin(),queries.end());
    int block = sqrt(m);
    vector<int> ans(q);
    int ci = 0;
    //cout << "starting blcoking!\n";
    for(int i = 0; i*block < m;i++){
        int h = (i+1)*block;
        //cout << "i: " << i << " h: " << h<<endl;
        vector<pair<pii,int>> curblock;
        while(ci < q &&queries[ci].F.F < h){
            //cout << "queries[ci].F.F: " << queries[ci].F.F<<endl;
            curblock.push_back(queries[ci]);
            ci++;
        }
        //cout << "CURRENT BLOCK SIZE! " <<curblock.size();
        sort(curblock.begin(),curblock.end(),compareSecond);
        int it = 0; 
        dsu d;
        d.init(n);
        while(it < curblock.size() && curblock[it].F.S < h){
            d.setcp();
            for(int l = curblock[it].F.F; l <= curblock[it].F.S; l++){
                d.join(edges[l].F,edges[l].S);
            }
            ans[curblock[it].S] = d.numdisjoint;
            it++;
            d.undojoins();
        }
        int c = h;
        while(it < curblock.size()){
            auto cur = curblock[it];
            while(c <= cur.F.S){
                d.join(edges[c].F,edges[c].S);
                c++;
            }
            d.setcp();
            int toleft = h-1;
            while(toleft >= cur.F.F){
                d.join(edges[toleft].F,edges[toleft].S);
                toleft--;
            }
            ans[curblock[it].S] = d.numdisjoint;
            d.undojoins();
            it++;
        }
    }
    for(int i : ans){
        cout << i << "\n";
    }

}
