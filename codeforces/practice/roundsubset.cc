#include <bits/stdc++.h>

using namespace std;
#define MAXN 205

int dp[MAXN][MAXN][MAXN];

int arr[MAXN];
int cnt2[MAXN];
int cnt5[MAXN];
int n,k;
int main(){
	cin >> n >> k;
	int total5 = 0;
	for(int i =0; i < n; i++){
		int a; cin >> a;
		arr[i] = a;
		while(a%2 == 0 && a > 0){
			a/=2;
			cnt2[i]++;
		}
		a = arr[i];
		while(a%5 == 0 && a > 0){
			a/=5;
			cnt5[i]++;
		}
		total5+=cnt5[i];
	}
	total5 = min(total5, MAXN);
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int l = 0; l < total5; l++){
				dp[i+1][j+1][l+cnt5[i]] = max(dp[i+1][j+1][l+cnt5[i]],dp[i][j][l]+cnt2[i]);
				dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
				ans = max(ans,min(dp[i][j][l],l));
			}
		}
	}
	for(int i =0; i < n)
	cout << ans;
}