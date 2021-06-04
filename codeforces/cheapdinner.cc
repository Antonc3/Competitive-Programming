#include <bits/stdc++.h>
using namespace std;
#define MAXN 150000
#define f first
#define s second
const int INF = 2e9;
int n[4];
int prices[4][MAXN];
vector<int> dgw[3][MAXN];
int dp[4][MAXN];
int solve(){
	for(int i =0; i < n[0]; i++){
		dp[0][i] = prices[0][i];
	}
	for(int i =1; i < 4; i++){
		multiset<int> ms;
		for(int j =0; j < n[i-1];  j++){
			ms.insert(dp[i-1][j]);
		}
		for(int j = 0; j < n[i]; j++){
			for(auto q : dgw[i-1][j]){
				ms.erase(ms.find(dp[i-1][q]));
			}
			if(ms.empty())
				dp[i][j] = INF;
			else
				dp[i][j] = min(INF,*ms.begin() + prices[i][j]);
			for(auto q : dgw[i-1][j]){
				ms.insert(dp[i-1][q]);
			}
		}
	}
	int ans = INF+11;
	for(int i =0; i < n[3]; i++){
		ans = min(ans,dp[3][i]);
	}
	if(ans >= INF){
		return -1;
	}
	return ans;
}
int main(){
	for(int i = 0; i < 4; i++) cin >> n[i];
	for(int i =0; i < 4; i++){
		for(int j = 0; j < n[i]; j++){
			cin >> prices[i][j];
			// cout << "here: " << prices[i][j] <<" "<< j<<endl;
		}
	}
	for(int i =0; i < 3; i++){
		int m;
		cin >> m;
		for(int j = 0; j < m; j++){
			int a,b;
			cin >> a >> b;
			a--;
			b--;
			dgw[i][b].push_back(a);
		}
	}
	cout << solve();
}