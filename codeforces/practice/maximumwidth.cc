#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n,m;
string s,t;
int dp[MAXN][2];
int main(){
	cin >> n >> m >> s >> t;
	int cur = 0;
	for(int i =0; i < n; i++){
		if(cur < m && s[i] == t[cur]){
			dp[cur][0] = i;
			cur++;
		}
	}
	cur = m-1;
	for(int i =n-1; i >= 0; i--){
		if(cur >=0 && s[i] == t[cur]){
			dp[cur][1] = i;
			cur--;
		}
	}
	int ans = 0;
	for(int i = 0; i < m-1; i++){
		ans = max(ans,dp[i+1][1]-dp[i][0]);
	}
	cout << ans;
}