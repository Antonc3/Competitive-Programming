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
int main(){
    int n,m;
    cin >> n >> m;
    dsu d;
    d.init(n);
    vector<int> ans;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(s == "persist"){
            d.setcp();
        }
        else if(s=="union"){
            int a,b;
            cin >> a >> b;
            a--; b--;
            d.join(a,b);
            ans.push_back(d.numdisjoint);
        }
        else{
            d.undojoins();
            ans.push_back(d.numdisjoint);
        }
    }
    for(int i : ans) cout << i << "\n";
}
