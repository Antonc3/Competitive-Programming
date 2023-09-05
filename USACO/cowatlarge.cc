#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

vector<int> adj[MAXN];

int n,k;

int dpth[MAXN];
int distToLeaf[MAXN];
int ans = 0;
void dfs(int cur, int par){
	distToLeaf[cur] = MAXN+1;
	if(par == -1){
		dpth[cur] = 0;
	}
	else{
		dpth[cur] = dpth[par]+1;
	}
	if(adj[cur].size() == 1){
		distToLeaf[cur] = 0;
	}
	for(int i : adj[cur]){
		if(i != par){
			dfs(i,cur);
			distToLeaf[cur] = min(distToLeaf[cur],distToLeaf[i]+1);
		}
	}
}
void dfsDistToLeaf(int cur,int par){
	if(par != -1){
		disToLeaf[cur] = min(distToLeaf[cur],distToLeaf[par]+1);
	}
	for(int i : adj[cur]){
		if(i != par){
			dfsDistToLeaf(i,cur);
		}
	}
}
void dfsAns(int cur,int par){
	if(par!= -1){
		if(dpth[par] < distToLeaf[par] && dpth[cur] >= distToLeaf[cur]){
			ans++;
		}
	}
	for(int i : adj[cur]){
		if(i != par) dfsAns(i,cur);
	}
}
int main(){
	cin >> n >> k;
	for(int i =0; i < n-1;i++){
		int a,b;
		cin >> a>> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(adj[k].size() == 1){
		cout << 1;
	}
	else{
		dfs(k,-1);
		dfsDistToLeaf(k,-1);
		cout << ans<<endl;
	}
}