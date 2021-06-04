#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int n, k,z;
long long int dp[100002][6];
int ind[100002][6];

long long int solve(int kk, int zz, int i){
	if(kk==k-1 || i >=n || i < 0){
		return 0;
	}
	if(dp[kk][zz] != -1){
		return dp[kk][zz];
	}
	long long int val = 0;
	if(i < n){
		val = max(val, arr[i]+solve(kk+1,zz,i+1));
	}
	if(zz < z && i > 0){
		val = max(val,arr[i]+solve(kk+1,zz+1,i-1));
	} m
	return val;
}

long long int solve(){
	for(int i =0; i < z; i++){
		dp[0][i] = arr[0];
		dp[1][i] = arr[0]+arr[1];
		dp[2][i] = arr[0]+arr[1]+arr[2];
		ind[0][i] = 0;
		ind[1][i] = 1;
		ind[2][i] = 2; 
	}
	for(int i = 1; i < k; i++){
		dp[i][0] = dp[i-1][0] + arr[i];
		ind[i][0] = i;
	}
	int index = 0;
	if(n == 2){
		return arr[0]+arr[1];
	}
	if (n==3){
		if(z==1){
			return max(arr[0]+arr[1]+arr[2],arr[0]+arr[0]+arr[1]);
		}
		return arr[0]+arr[1]+arr[2];
	}
	for(int zz = 1; zz < z; zz++){
		long long int m = 0;
		for(int kk = 3; kk < k; kk++){
			m=0;
			if(arr[kk][zz-1] >= arr[kk-1][zz]+ind[kk]){
				dp[kk][zz] = dp[kk][zz-1];
				m=dp[kk][zz-1];
				ind[kk][zz] = ind[kk][zz-1];
			}
			else{
				dp[kk][zz] = dp[kk-1][zz]+arr[kk];
				m=dp[kk-1][zz]+ind[kk];
				ind[kk][zz] = ind[kk-1][zz]+1;
			}
			if(arr[kk-2][zz-1]+arr[k-3]+arr[k-2] > m){
				arr[kk] = kk-2
			}
		}
		if(dp[k-2][z-1]+arr[k-2] > max){
			dp[k-1][zz] = dp[k-2][z-1]+arr[k-2];
			ind[k-1][zz] = ind[k-2][zz-1]+1
		}
	}
	return dp[k-1][z-1];
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> k >> z;
		for(int i =0 ; i < n; i++){
			cin >> arr[i];
		}
		memset(dp,-1,sizeof(dp));
		cout << solve(0,0,0) <<endl;
	}
}