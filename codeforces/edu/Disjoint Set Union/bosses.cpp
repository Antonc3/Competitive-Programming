#include <bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> par;
    vector<int> bosspass;
    void init(int n){
        par = vector<int>(n);
        bosspass = vector<int>(n,0);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }
    int get(int a){
        if(par[a] == a){
            return a;
        }
        return par[a] = get(par[a]);
    }
    int updbp(int a){
        if(par[a] == a){
            return 0;
        }
        return bosspass[a]+=updbp(par[a]);
    }

    void join(int a, int b){
        if(a==b) return;
        bosspass[a]++;
        par[a] = b;
        updbp(a);
        get(a);
    }
};


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> ans;
    dsu dsu1;
    dsu1.init(n);
    for(int i = 0; i < m; i++){
        int a;
        int b,c;
        cin >> a;
        if(a==1){
            cin >> b >> c;
            b--;
            c--;
            dsu1.join(b,c);
        }
        else{
            cin >> b;
            b--;
            ans.push_back(dsu1.updbp(b));
            dsu1.get(b);
        }
    }
    for(int i : ans) cout << i<<endl;

}
