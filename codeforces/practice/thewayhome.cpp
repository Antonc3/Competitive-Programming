#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define F first
#define S second

const bool DEBUG = false;
const ll INF = 1e18;
void solve(){
    int n,m,p;
    cin >> n >> m >> p;
    vector<ll> profit(n);
    for(ll &x : profit) cin >> x;
    vector<vector<pair<int,ll>>> adj(n,vector<pair<int,ll>>());
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        adj[from].push_back({to,cost}); 
    }
    vector<vector<pii>> costTo(n+1,vector<pii>(n+1,{INF,0}));
    costTo[0][0] = {0,p};
    priority_queue<pair<pii,pair<int,int>>> pq;
    //dist, current coins, max profit, index
    pq.push({{0,p},{0,0}});
    ll cntr = 0;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll curPerf = -cur.F.F;
        ll curMon = cur.F.S;
        ll curNode = cur.S.S;
        ll curBest = cur.S.F;
        if(costTo[curNode][curBest].F != curPerf || 
                costTo[curNode][curBest].S != curMon){
            continue;
        }
        for(auto edge : adj[curNode]){
            ll ecost = edge.S;
            ll money = curMon;
            ll needToMakeup =  ecost-money;
            ll numPerformances = curPerf;
            ll curperform = curBest;
            if(edge.S > money){
                ll extraPerformances = needToMakeup/profit[curperform]+(needToMakeup%profit[curperform]!=0);
                numPerformances += extraPerformances;
                money += extraPerformances*profit[curperform];
            }
            money-=ecost;
            if(profit[curperform] < profit[edge.F]){
                curperform = edge.F;
            }
            if(costTo[edge.F][curperform].F > numPerformances
                    || (costTo[edge.F][curperform].F == numPerformances && costTo[edge.F][curperform].S < money)){

                costTo[edge.F][curperform] = {numPerformances,money};
                pq.push({{-numPerformances,money},{curperform,edge.F}});
            }
        }
        if(cntr > 30*n*m){
            break;

        }
        cntr++;
    }
    ll ans = INF;
    for(int i = 0; i < n; i++){
        ans= min(ans,costTo[n-1][i].F);
    }
    if(ans==INF) cout << "-1\n";
    else cout << ans <<"\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
