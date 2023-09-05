#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 500005
int arr[MAXN];
int dp[MAXN][2];
int n;
int main(){
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	cin >> n;
	// vector<int> arr(n,0);
	for(int i=0; i < n; i++){
		cin >> arr[i];
		arr[i]*=2;
		dp[i][0] = 2000000000;
		dp[i][1] = 2000000000;
	}
	sort(arr, arr+n);
	int lsti = 0;
	dp[0][0] = 0;
	for(int i =1; i < n; i++){
		while(lsti+1<n && arr[i]-arr[lsti+1] > dp[lsti+1][0]+2){
			lsti++;
		}
		dp[i][0] = min(arr[i]-arr[lsti],dp[lsti+1][0]+2);
	}
	// for(int i =0;i < n; i++){
	// 	cout << dp[i][0] << " ";
	// }
	lsti = n-1;
	dp[n-1][1] = 0;
	for(int i =n-2; i >=0; i--){
		while(lsti-1>0 && arr[lsti-1]-arr[i] > dp[lsti-1][1]+2){
			lsti--;
		}
		dp[i][1] = min(arr[lsti]-arr[i],dp[lsti-1][1]+2);
	}
	//  for(int i =0;i < n; i++){
	// 	cout << dp[i][0] << " ";
	// }
	// cout << endl;
	//  for(int i =0;i < n; i++){
	// 	cout << dp[i][1] << " ";
	// }
	int i = 0;
	int j = n-1;
	int ans = 2000000000;
	while(i < j){
		ans = min(ans,max((arr[j]-arr[i])/2,2+max(dp[i][0],dp[j][1])));
		if(dp[i+1][0] < dp[j-1][1]){
			i++;
		}
		else{
			j--;
		}
	}
  	cout << ans / 2 << '.' << (ans % 2 ? 5 : 0) << '\n';


}