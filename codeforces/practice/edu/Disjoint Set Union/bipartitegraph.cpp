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
        sz = vector<int>(n);
        len = vector<int>(n);
        for(int i =0; i< n; i++){
            par[i] = i;
            sz[i] = 1;
            len[i] = 0;    
        }
    }
    pii get(int a){
        if(par[a] == a){
            return {a,0};
        }
        auto val = get(par[a]);
        par[a] = val.F;
        len[a] = (len[a] + val.S)%2;
        return {par[a],len[a]};
    }
    void join(int a, int b){
        auto va = get(a); 
        auto vb = get(b); 
        if(sz[va.F] > sz[va.S]) swap(va,vb);
        sz[vb.F] += sz[va.F];
        len[va.F] = (va.S+vb.S+1)%2;
        par[va.F] = vb.F;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    dsu d;
    d.init(n);
    int shift = 0;
    for(int i =0;i<m;i++){
        int a,b,c;
        cin >> a>> b>>c;
        b = (b+shift)%n;
        c = (c+shift)%n;
        if(a==0){
            d.join(b,c);
        }
        else{
            auto bb = d.get(b);
            auto cc = d.get(c);
            if(cc.S == bb.S){
                cout << "YES\n";
                shift++;
                shift%=n;
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
