#include <bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> par;
    void init(int n){
        par = vector<int>(n);
        for(int i =0; i < n; i++){
            par[i] = i;
        }
    }
    int get(int a){
        return par[a] = ((par[a] == a) ? a : get(par[a]));
    }
    void unite(int a,int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        par[a] = b;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> ans(n);
    dsu dsu1;
    dsu1.init(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a = dsu1.get(a-1);
        ans[i] = a;
        dsu1.unite(a,(a+1)%n);
    }
    for(int i : ans) cout << i+1 << " ";
}
