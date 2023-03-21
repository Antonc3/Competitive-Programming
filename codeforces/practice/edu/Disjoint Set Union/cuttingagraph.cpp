#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct dsu{
    vector<int> par;
    vector<int> sz;
    void init(int n){
        sz = vector<int>(n+1);
        par = vector<int>(n+1);
        for(int i = 0; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int a){
        return (par[a] == a) ? a : get(par[a]);
    }

    void unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b];
        par[b] = a;
    }
};

vector<int> adj[MAXN];
struct inp{
    string s;
    int a, b;
};

vector<inp> inputs;
int main(){
    int n,m,k;
    
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
    }
    for(int i = 0; i < k; i++){
        string s;
        int a,b;
        cin >> s >> a >> b; 
        inputs.push_back({s,a,b});
    }
    vector<string> ans;
    reverse(inputs.begin(),inputs.end());
    dsu dsu1;
    dsu1.init(n+2);
    for(int i = 0; i < inputs.size(); i++){
        int a = inputs[i].a;
        int b = inputs[i].b;
        if(inputs[i].s == "ask"){
            ans.push_back((dsu1.get(a)==dsu1.get(b)) ? "YES" : "NO");
        }
        else{
            dsu1.unite(a,b);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto s : ans) cout << s << "\n";

}
