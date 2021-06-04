#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
vector<int> adj[MAXN];
int dp[2][MAXN];
int n,m;
int visited[MAXN];
void dfs(int c, int up){
	visited[c] = true;
	for(int to : adj[c]){
		if(!visited[to]){
			if(c < to && !up){
				dp[1][to] = min(dp[1][to], )
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <=n; i++){
			adj[i].clear();
			dp[0][i] = i-1;
			dp[1][i] = i-1;
			visited[i] = false;
		}
		for(int i =0; i < m; i++){
			int a,b;
			cin >> a >> b;
			adj[b].push_back(a);
		}
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dfs(i);
			}
		}
	}
}