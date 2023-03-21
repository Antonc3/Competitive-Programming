#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
#define MAXN 100005

int n,m;
vector<pii> g[MAXN];
vector<int> par;
bool check(double val){
    priority_queue<pii> q;
    vector<double> best(n+1,1e9);
    par = vector<int>(n+1,0);
    par[1] = -1;
    q.push({0,1});
    best[1] = 0;
    while(!q.empty()){
        pii cur = q.top();
        q.pop();
        for(pii edge : g[cur.S]){
            if(best[edge.F] <= best[cur.S]+edge.S-val) continue;
            best[edge.F] = best[cur.S]+edge.S-val;
            par[edge.F] = cur.S;
            q.push({-best[edge.F],edge.F});
        }
    }
    return best[n] <= 0.0;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
    }
    double l = 0, r = 200.0;
    double best = 200.0;
    for(int i =0; i < 100; i++){
        double mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            r = mid;
        }
        else{
            l = mid;
        }
    }
    check(best);
    vector<int> ans;
    for(int i = n; i != -1; i = par[i]){
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size()-1<<"\n";
    for(int i : ans) cout << i << " ";
}
