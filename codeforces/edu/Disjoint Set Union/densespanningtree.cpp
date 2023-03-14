#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int INF = 2e9+10;

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
    void join(int a, int b){
        a = get(a);
        b = get(b);
        if(a==b) return;
        if(sz[a] > sz[b]) swap(a,b);
        sz[b]+=sz[a];
        par[a] = b;
    }
};

int n,m;
vector<pair<int,pair<int,int>>> edges;

int check(int ind){
    int cnt = 0;
    int diff = 0;
    dsu d;
    d.init(n);
    int fir = edges[ind].first;
    for(int i = ind; i < m; i++){
        if(cnt+1 == n) break;
        auto cur = edges[i];
        int a = cur.second.first;
        int b = cur.second.second;
        a = d.get(a);
        b = d.get(b);
        if(a==b) continue;
        cnt++;
        d.join(a,b);
        diff = max(diff,cur.first-fir);
    }
    if(cnt+1==n) return diff;
    return INF;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({c,{b,a}});
    }
    sort(edges.begin(),edges.end());
    int ans = INF;
    for(int i = 0; i < m; i++){
        ans = min(ans,check(i)); 
    }
    if(ans==INF) cout << "NO\n";
    else{
        cout << "YES\n" << ans << "\n";
    }
}
