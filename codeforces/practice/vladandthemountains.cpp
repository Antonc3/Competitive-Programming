#include <bits/stdc++.h>
using namespace std;

struct dsu {
    vector<int> s;
    void init(int n){
        s = vector<int>(n,-1);
    }
    int get(int i){
        return (s[i] >= 0) ? s[i] = get(s[i]) : i;
    }
    bool unite(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return false;
        if(s[a] > s[b]) swap(a,b);
        s[b] += s[a];
        s[a] = b;
        return true;
    }
};
struct query
{
    int a, b, e, ind;
    void init(int aa, int bb, int ee, int i)
    {
        a = aa;
        b = bb;
        e = ee;
        ind = i;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> heights(n);
    vector<int> heightIndex(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
        heightIndex[i] = i;
    }
    sort(heightIndex.begin(), heightIndex.end(),
         [&](const int &a, const int &b) -> bool
         {
             return heights[a] < heights[b];
         });
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<query> queries(q);
    vector<pair<int,int>> roads;
    for(int i = 0; i < q; i++){
        int a, b, e;
        cin >> a >> b >> e;
        a--; b--;
        query quer;
        quer.init(a,b,e,i);
        queries[i] = quer;
        pair<int,int> p = make_pair(heights[a]+e, i);
        roads.push_back(p);
    }
    sort(roads.begin(),roads.end());
    vector<int> visitd(n);
    vector<int> ans(q);
    dsu d;
    d.init(n);
    int hiInd = 0;
    for(int i = 0; i < q; i++){
        auto cur = roads[i];
        while(hiInd < n && heights[heightIndex[hiInd]]  <= cur.first){
            for(auto dest : adj[heightIndex[hiInd]]){
                if(heights[dest] <= heights[heightIndex[hiInd]]){
                    d.unite(dest,heightIndex[hiInd]);
                }
            }
            hiInd++;
        }
        if(d.get(queries[cur.second].a) == d.get(queries[cur.second].b)){
            ans[cur.second] = 1;
        }
    }
    for(int i : ans) cout << ((i) ? "YES" : "NO") << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}