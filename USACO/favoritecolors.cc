#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
int n,m;
int par[MAXN],cnt[MAXN];
int size[MAXN];
vector<int> adj[MAXN];
queue<int> q;

int findPar(int a){
	return (par[a] == a) ? a : par[a] = findPar(par[a]);
}

int main(){
	freopen("fcolor.in","r",stdin);
	freopen("fcolor.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i =1; i <= n; i++){
		par[i] = i;
		size[i] = 1;
		if(adj[i].size() > 1) q.push(i);
	}
	while(!q.empty()){
		int cur = q.front();
		if(adj[cur].size() <= 1){
			q.pop();
			continue;
		}
		int a = findPar(adj[cur].back());
		adj[cur].pop_back();
		int b = findPar(adj[cur].back());
		if(a == b) continue;
		//we want a to be bigger
		if(size[a] < size[b]){
			swap(a,b);
		}
		size[a] += size[b]; par[b] = a;
		adj[a].insert(end(adj[a]),begin(adj[b]),end(adj[b])); 
		adj[b].clear();
		if(adj[a].size() > 1) q.push(a);
	}
	int color = 1;
	for(int i =1; i <= n; i++){
		int iPar = findPar(i);
		if(cnt[iPar] == 0){
			cnt[iPar] = color;
			color++;
		}
		cout << cnt[iPar] <<endl;
	}
}