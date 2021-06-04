#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> adj[100005];

//colors are 1,2,3
int color[100005];

long long dp[100005][3];

long long m = 1e9+7;

int n,k;

int dfs(int cV, int cC, int pV, int pC){
	if((color[cV] != cC && color[cV] >= 0) || cC == pC) return 0;
	if(dp[cV][cC] >= 0) return dp[cV][cC];
	dp[cV][cC] = 1;
	for(int to : adj[cV]){
		if(to != pV){
			long long sum = 0;
			for(int i =0; i < 3; i++){
				sum+=dfs(to,i,cV,cC);
				sum%=m;
			}
			dp[cV][cC] *= sum;
			dp[cV][cC] %= m;
		}
	}
	return dp[cV][cC];
}

int main(){
	ifstream cin ("barnpainting.in");

	ofstream cout ("barnpainting.out");
	cin >> n >> k;
	for(int i =0; i < n-1; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i =0; i <= n; i++){
		color[i] = -1;
		for(int j =0; j < 3; j++){
			dp[i][j] = -1;
		}
	}
	for(int i =0; i < k; i++){
		int a,b;
		cin >> a >>b;
		b--;
		color[a] =b;
	}
	long long ans = dfs(1,0,-1,-1) + dfs(1,1,-1,-1) + dfs(1,2,-1,-1);
	ans%=m;
	cout << ans;
}