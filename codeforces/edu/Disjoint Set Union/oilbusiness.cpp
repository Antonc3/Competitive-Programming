#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    void join(int a,int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        sz[b] += sz[a];
        par[a] =b;
    }
};
int main(){
    int n,m;
    ll s;
    cin >> n >> m >> s;
    vector<int> visited(m,0);
    vector<pair<pair<int,int>,pair<int,int>>> v;
    ll totalWeight = 0;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >>c;
        a--; b--;
        totalWeight+=c;
        v.push_back({{c,i},{a,b}});
    }
    sort(v.begin(),v.end(),[&](pair<pair<int,int>,pair<int,int>> a,pair<pair<int,int>,pair<int,int>> b){ return a.first.first > b.first.first;});
    //for(auto i : v) cout << i.first.first << " ";
    int usedEdges = 0;
    ll usedWeight = 0;
    dsu d;
    d.init(n);
    for(int i = 0; i < m; i++){
        auto cur = v[i];
        int a = cur.second.first;
        int b = cur.second.second;
        a = d.get(a);
        b = d.get(b);
        if(a==b) continue;
        usedWeight+=cur.first.first;
        usedEdges++;
        d.join(a,b);
        visited[i] = true;
        //cout << "i: " << i << endl;
        if(usedEdges==n-1) break;
    }
    //cout << "usedEdges: " << usedEdges << endl;
    //cout <<"usedWeight: " << usedWeight << endl;
    //cout <<"totalWeigh: " << totalWeight << endl;
    vector<int> ans;
    for(int i = 0; i < m; i++){
        if(visited[i]) continue;
        int remweight = totalWeight-usedWeight;
        if(totalWeight-usedWeight > s){
            visited[i] = true;
            usedWeight+=v[i].first.first;
            usedEdges++;
        }
        if(!visited[i]){ 
            ans.push_back(v[i].first.second);
        }
    }
    sort(ans.begin(),ans.end());
    cout << m-usedEdges << endl;
    for(int i : ans) cout << i+1 << " ";
    cout << "\n";
}
