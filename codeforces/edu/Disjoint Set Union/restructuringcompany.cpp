#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> par;
    vector<int> sz;
    void init(int n){
        par = vector<int>(n);
        sz = vector<int>(n);
        for(int i= 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int get(int a){
        return par[a] = (par[a] == a) ? a : get(par[a]);
    }
    void unite(int a,int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        par[a] = b;
        sz[b] += sz[a];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n>>m;
    dsu dsu1;
    dsu1.init(n);
    set<int> nxt;
    for(int i = 0; i < n; i++) nxt.insert(i);
    vector<string> ans;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        b--; c--;
        if(a==1){
            dsu1.unite(b,c);
        }
        else if(a==2){
            int pos = b;
            while(*nxt.lower_bound(pos) < c){
                pos = *nxt.lower_bound(pos);
                dsu1.unite((pos),(pos)+1);
                nxt.erase(pos);
            }
        }
        else{
            ans.push_back((dsu1.get(c)==dsu1.get(b)) ? "YES" : "NO"); 
        }
    }
    for(auto s : ans) cout << s << "\n";
}
