#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

struct dsu{
    vector<int> par;
    vector<int> len;
    vector<int> sz;
    void init(int n){
        par = vector<int>(n);
        len = vector<int>(n);
        sz = vector<int>(n);
        for(int i =0;i < n; i++){
            par[i] = i;
            len[i] = 0;
            sz[i] = 1;
        }
    }
    pii get(int a){
        if(par[a] == a){
            return {a,len[a]};
        }
        auto val = get(par[a]);
        par[a] = val.F;
        len[a] = (len[a]+val.S)%2;
        return {par[a],len[a]};
    }
    void join(int a, int b){
        auto va = get(a);
        auto vb = get(b);
        if(sz[va.F] > sz[vb.F]) swap(va,vb);
        par[va.F] = vb.F;
        len[va.F] = (va.S+vb.S+1)%2;
        sz[vb.F]+=sz[va.F];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    int ind = -1;
    dsu d;
    d.init(n);
    for(int i = 1; i <= m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        auto va = d.get(a);
        auto vb = d.get(b);
        if(va.F == vb.F && va.S == vb.S && ind == -1) ind = i;
        d.join(a,b);
    }
    cout << ind << endl;
}
