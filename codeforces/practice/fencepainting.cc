#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m;
int ans[MAXN];
int A[MAXN];
int B[MAXN];
int C[MAXN];
int lastColor[MAXN];
vector<int> lft[MAXN];
void solve(){
	cin >> n >> m;
	// fill(lastColor, lastColor+n+1,-1);
	for(int i = 0; i <= n; i++){
		lft[i].clear();
	}
	int toColor = 0;
	for(int i =0; i < n; i++){
		cin >> A[i];
	}
	for(int i =0; i < n; i++){
		cin >> B[i];
		// lastColor[B[i]]=i;
		if(A[i] != B[i]){
			toColor++;
			lft[B[i]].push_back(i);
		}
	}
	for(int i =0; i < m; i++){
		cin >> C[i];
	}
	int last = -1;
	if((int)lft[C[m - 1]].size() > 0){
		last = lft[C[m - 1]].back();
		lft[C[m - 1]].pop_back();
	}
	else{
		for(int i = 0 ;i < n;i++){
			if(B[i] == C[m - 1]){
				last = i;
				break;
			}
		}
	}
	if(last == -1){
		cout << "NO\n";
		return;
	}
	ans[m-1] = last;
	for(int i =0; i < m-1; i++){
		if(lft[C[i]].empty()){
			ans[i] = last;
		}
		else{
			ans[i] = lft[C[i]].back();
			lft[C[i]].pop_back();
			toColor--;
			continue;
		}
		
	}
	for(int i =1; i <= n; i++){
		if(!lft[i].empty()){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i =0; i < m; i++){
		cout << ans[i]+1 << " ";
	}
	cout << endl;
	return;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}