#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define f first
#define s second
int n,m;
vector<pair<int,int>> edges[MAXN];
int dist[MAX];
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		edges[a].push_back({b,c});
		edges[b].push_back({a,c});
	}
	priority_queue<pair<pair<int,int>,pair<int,int>> pq;
	pq.push({{0,1},{0,0}});
	fill(dist,dist+n,-1);
	dist[1] = 0;
	while(!pq.empty()){
		auto tp = pq.top(); pq.pop();
		for(auto i : edges[tp.f.s]){
			
		}
	}
}