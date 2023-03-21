#include <bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> par;
    vector<int> sz;
    vector<int> mx;
    
    void init(int n){
        par = vector<int>(n+1);
        mx = vector<int>(n+1);
        sz = vector<int>(n+1);
        for(int i = 0; i <= n; i++){
            par[i] = i;
            mx[i] = i;
            sz[i] = 1;
        }
    }

    int get(int x){
        return par[x] = (par[x] == x) ? x : get(par[x]);
    }

    void unite(int a, int b){
        a = get(a);
        b = get(b);
        if(sz[a] > sz[b]){
            swap(a,b);
        }
        par[a] = b;
        sz[b]+=sz[a];
        mx[b] = max(mx[a],mx[b]);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >>n >> m;
    dsu dsu1;
    dsu1.init(n+1);
    for(int i =0; i < m; i++){
        char c;
        int a;
        cin >> c >> a;
        if(c=='?'){
            int mx = dsu1.mx[dsu1.get(a)];
            cout << ((mx==n+1) ? -1 : mx)<<"\n";
        }
        else{
            dsu1.unite(a,a+1);
        }
    }
}
