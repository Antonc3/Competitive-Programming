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
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        par[a] = b;
        sz[b] += sz[a];
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i =0 ; i < k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        pq.push({-c,{a,b}});
    }
    int ans = 0;
    dsu d;
    d.init(n);
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int a = cur.second.first;
        int b = cur.second.second;
        a = d.get(a);
        b = d.get(b);
        if(a==b) continue;
        ans = max(ans,-cur.first);
        d.join(a,b);
    }
    cout << ans << "\n";
}
