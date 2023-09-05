#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long factorial[200005];
long long invFact[200005];

long long fast_pow(long long a, long long p) {
    long long res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % MOD;
            p /= 2;
        } else {
            res = (res * a) % MOD;
            p--;
        }
    }
    return res;
}

void precalcFactorials(){
	factorial[0] =invFact[0] = 1;
	for(int i =1; i < 200005; i++){
		factorial[i] = (i*factorial[i-1])%MOD;
		invFact[i] = fast_pow(factorial[i],MOD-2);
	}
}
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	int ar[n];
	for(int i =0; i < n; i++){
		cin >> ar[i];
	}
	sort(ar,ar+n);
	long long ans =0;
	int r =0;
	for(int l = 0; l < n; l++){
		while(r < n && ar[r]-ar[l] <= k){
			r++;
		}
		if((r == n && ar[r-1]-ar[l] > k) || r-l < m){
			continue;
		}
		int a = r-l-1;
		// cout << "r: " << r << " l: " << l <<endl;
		// cout << "adding: " << (factorial[a])/(factorial[m]*factorial[(a-m)])%MOD<<endl;
		ans+=(((factorial[a]*invFact[m-1])%MOD)*invFact[(a-m+1)])%MOD;
		ans%=MOD;
	}
	cout << ans<<endl;
}
int main(){
	int t;
	cin >> t;
	precalcFactorials();
	while(t--){
		solve();
	}
}