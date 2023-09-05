#include <bits/stdc++.h>

using namespace std;
int n;
void solve(){
	cin >> n;
	int n1,n2;
	int a = 1, b = 0;
	int ni1 = 1, ni2 = 0;
	cin >> n1;
	for(int i =2; i <= n; i++){
		int c;
		cin >> c;
		if(c  != n1){
			n2 = c;
			ni2++;
			b = i;
		}
		else{
			ni1++;
		}
	}	
	cout << ((ni1 == 1) ? a : b)<<endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}