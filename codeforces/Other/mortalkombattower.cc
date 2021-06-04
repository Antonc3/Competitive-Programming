#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
int n;
int dp[200005][2];
vector<int> v;

int solve(bool friendTurn,int ind){

	if(ind >n-1){
		return 0;
	}
	if(dp[ind][friendTurn] != -1){
		return dp[ind][friendTurn];
	}
	if(ind == n-1){
		if(friendTurn){
			return v[ind];
		}
		return 0;
	}
	if(friendTurn){
		int num1 = v[ind];
		int num2 = v[ind+1];
		if(ind == n-2){
			dp[ind][friendTurn] = num1;
			return num1;
		}
		dp[ind][friendTurn] = min(solve(false,ind+1)+num1,solve(false,ind+2)+num1+num2);
		return dp[ind][friendTurn];

	}
	else{
		dp[ind][friendTurn] = min(solve(true,ind+1),solve(true,ind+2));
		return dp[ind][friendTurn];
	}
}

int main(){
	int t;
	memset(dp,-1,sizeof(dp[0][0])*400010);
	cin >> t;
	while(t--){
		v.clear();
		cin >> n;
		for(int i =0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		cout << solve(true,0)<<endl;
		memset(dp,-1,sizeof(dp[0][0])*400010);
	}
}