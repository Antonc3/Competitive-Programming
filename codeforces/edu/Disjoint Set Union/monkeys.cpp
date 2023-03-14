#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

struct dsu{
    vector<int> par;
    vector<int> sz;
    vector<vector<int>> group;
    void init(int n){
        sz = vector<int>(n+1);
        par = vector<int>(n+1);
        group = vector<vector<int>>(n+1,vector<int>());
        for(int i = 0; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
            group[i].push_back(i);
        }
    }

    int get(int a){
        return par[a] = ((par[a] == a) ? a : get(par[a]));
    }

    void unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(a != 0 && sz[a] < sz[b]||b==0) swap(a,b);
        sz[a]+=sz[b];
        par[b] = a;
        group[a].insert(group[a].end(),group[b].begin(),group[b].end());
    }
};

int monkey[MAXN][2];
int seen[MAXN][2];

int main(){
    int n,m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        monkey[i][0] = a;
        monkey[i][1] = b;
        seen[i][0] = 0;
        seen[i][1] = 0;
    }
    vector<int> ans(n,-1);
    dsu dsu1;
    dsu1.init(n);
    vector<pair<int,int>> inp;
    for(int i = 0; i < m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        inp.push_back({a,b});
        seen[a][b] = 1;
    }
    for(int i =0; i < n; i++){
        if(!seen[i][0] && monkey[i][0] >= 0){
            dsu1.unite(i,monkey[i][0]);
        }
        if(!seen[i][1] && monkey[i][1] >= 0){
            dsu1.unite(i,monkey[i][1]);
        }
    }
    for(int i = m-1; i >= 0; i--){
        auto cur = inp[i];
        int a = monkey[cur.first][cur.second];
        int b = cur.first;
        int aa = dsu1.get(a);
        int bb = dsu1.get(b);
        //cout << "time: " << i << endl;
        //cout << "a: " << a << " b: " << b << endl;
        //cout << "aa: " << aa << " bb: " << bb << endl;
        //for(int j : dsu1.par) cout << j << " ";
        //cout << "\n \n";
        if(aa == 0 && bb != 0){
            for(int j : dsu1.group[bb]){
                ans[j] = i;
            }
        }
        else if(aa != 0 && bb == 0){
            for(int j : dsu1.group[aa]){
                ans[j] = i;
            }
        }
        dsu1.unite(a,b);
    }
    for(auto i : ans) cout << i << "\n";
}

