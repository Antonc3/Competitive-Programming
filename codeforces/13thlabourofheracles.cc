#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int degree[MAXN];
int n;
int weights[MAXN];
void solve(){
	cin >> n;
	fill(degree,degree+n+1,0);
	int weightSum = 0;
	for(int i =1; i <= n; i++){
		cin >> weights[i];
		weightSum+=weights[i];
	}
	for(int i =0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		degree[a]++;
		degree[b]++;
	}
	long long int ans = 0;
	vector<int> tosort;
	for(int i =1; i <= n; i++){
		for(int j = 1; j < degree[i];j++){
			tosort.push_back(weights[i]);
		}
		ans+=weights[i];
	}
	sort(tosort.begin(), tosort.end());
	reverse(tosort.begin(), tosort.end());
	for(int i =0; i < tosort.size(); i++){
		cout << ans<<" ";
		ans+=tosort[i];
	}
	cout <<ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}