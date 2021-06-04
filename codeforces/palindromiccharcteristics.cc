#include <bits/stdc++.h>

using namespace std;

string s;

long long arr[5005];


long long dp[5000][5000];

// void generateHashes(){
// 	for(int i =0; i < s.length; i++){
// 		long long d = 1;
// 		hashes[i][i] = (arr[i]-'a');
// 		for(int j =i+1; j < s.length; j++){
// 			hashes[i][j] = (hashes[i][j-1]+(arr[j]-'a')*d)%MOD;
// 			d*=mult;
// 			d%=MOD;
// 		}
// 	}
// 	for(int i =s.lenght-1; i >=0; i--){
// 		long long d = 1;
// 		hashes[i][i] = (arr[i]-'a');
// 		for(int j =i-1; j >=0; j--){
// 			hashes[i][j] = (hashes[i][j+1]+(arr[j]-'a')*d)%MOD;
// 			d*=mult;
// 			d%=MOD;
// 		}
// 	}
// }
int n;
void solve(){
	n = s.size();
	for(int i = 1; i<=n; i++){
		for(int l = 0; l < n; l++){
			int r = l+i;
			if(i == 1){
				dp[l][r] =1;
				continue;
			}
			if(i==2){
				if(s[l] == s[r-1]) dp[l][r-1] = 2;
				else dp[l][r] = 0;
				continue;
			}
			if(s[l] != s[r] || dp[l+1][r-1] == 0){
				continue;
			}
			dp[l][r] = 1;
			int mid = (l+r)/2;
			if(i&1){
				if(dp[l][m] == dp[m+1][r])	dp[l][r] = dp[l][m]+1;
			}
		
			else{
				if(dp[l][m] == dp[m][r])dp[l][r] = dp[l][m]+1;
			}
		}
	}
	for(int i =0; i < n; i++){
		for(int j =i; j < n; j++){
			arr[dp[l][j]]++;
		}
	}
	for(int i = n-1; i >=1;i++){
		arr[i] +=arr[i+1];
	}
}

int main(){
	cin >> s;
	solve();
	for(int i=1; i <= n; i++){
		cout <<arr[i] << " ";
	}
}