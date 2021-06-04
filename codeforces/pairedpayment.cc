#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define f first
#define s second
pair<int,int> dp[2][MAXN];
vector<pair<int,int>> adj[MAXN];
int n,m;
int main(){
	cin >> n >> m;
	for(int i =0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	for(int i =0; i <= n; i++){
		dp[0][i] = {1e9,1e9};
		dp[1][i] = {1e9,1e9};
	}
	priority_queue<pair<pair<int,int>,pair<int,int>>> pq;
	pq.push({{0,0},{1,0}});
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		int nxt = (tp.s.s+1)%2;
		for(auto i :adj[tp.s.f]){
			if(nxt){
				if(dp[nxt][i.f].f+dp[nxt][i.f].s*dp[nxt][i.f].s
						< dp[tp.s.s][tp.s.f]+i.s*i.s){
					dp[nxt][i.f] = {dp[tp.s.s],i.s};
					pq.push({{dp[nxt][i.f].f+i.s*i.s}})
				}
			}
		}
	}
}