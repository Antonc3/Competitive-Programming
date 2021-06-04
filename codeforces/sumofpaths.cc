#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAXN 5005
const int MOD = 1e9+7;
int n,k,q;
// ll dp[MAXN][MAXN];
ll used[MAXN];
ll endin[MAXN][MAXN];
int ar[MAXN];
int main(){
	cin >> n >> k >> q;
	for(int i =0; i < n; i++){
		endin[i][0] = 1;
	}
	for(int kk =1; kk <=k; kk++){
		for(int i = 0; i < n; i++){
			endin[i][kk] = 0;
			if(i > 0){
				endin[i][kk] =(endin[i][kk]+ endin[i-1][kk-1])%MOD;
			}
			if(i < n-1){
				endin[i][kk] =(endin[i][kk]+ endin[i+1][kk-1])%MOD;
			}
		}
	}
	for(int i =0; i < n; i++){
		for(int j =0; j <= k; j++){
			used[i]+=(endin[i][j]*endin[i][k-j])%MOD;
			used[i]%=MOD;
		}
	}
	ll ans = 0;
	for(int i =0; i < n; i++){
		cin >> ar[i];
		ans+=ar[i]*used[i];
		ans%=MOD;
	}
	// for(int i = 0; i < n; i++){
	// 	cout << used[i] << " ";
	// }
	for(int i =0 ; i < q; i++){
		int a;
		ll b;
		cin >> a >> b;
		a--;
		ans = (ans-(ar[a]*used[a])%MOD+MOD)%MOD;
		ar[a] = b;
		ans = (ans+(ar[a]*used[a])%MOD+MOD)%MOD;
		cout << ans << endl;
	}
}