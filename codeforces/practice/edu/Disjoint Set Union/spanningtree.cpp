#include <bits/stdc++.h>
using namespace std;

struct dsu{
    vector<int> par;
    vector<int> sz;
    
    void init(int n){
        par = vector<int>(n);
        sz = vector<int>(n,1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }
    int get(int a){
        return par[a] = (par[a] == a) ? a : get(par[a]);
    }
    void join(int a,int b){
        a= get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        par[a] = b;
        sz[b] += sz[a];
    }
};


int main(){
    int n,m;
    cin >> n >> m;
    dsu d;
    d.init(n);
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        b--;
        a--;
        pq.push({-c,{a,b}});
    }
    long long total = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        //cout << "weight: " <<cur.first << endl;
        pq.pop();
        if(d.get(cur.second.first) == d.get(cur.second.second)) continue;
        d.join(cur.second.first,cur.second.second);
        total-=1ll*cur.first;
    }
    cout << total << endl;
}
