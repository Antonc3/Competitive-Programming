#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int arr[n];
		for(int i =0; i < n; i++){
			char c;
			cin >> c;
			if(c == '-'){
				arr[i] = -1;
			}
			else{
				arr[i] = 1;
			}
		}
		int pref[n];
		pref[0] = arr[0];
		int lar[n];
		int smal[n]
		if(arr[0] == 1){
			lar[0] = 1;
			smal[0] = 0;
		}
		else{
			lar[0] = 0;
			smal[0] = -1;
		}
		for(int i =1; i < n; i++){
			pref[i] = pref[i-1] + arr[i];
			lar[i] = max(pref[i],lar[i-1]);
			smal[i] = min(pref[i],smal[i-1]);
		}
		int prefBack[n];
		int larBack[n];
		int smalBack[n];
		prefBack[n-1] = arr[n-1];
		if(arr[n-1] == 1){
			larBack[n-1] = 1;
			smalBack[n-1] = 0;
		}
		else{
			larBack[n-1] = 0;
			smalBack[n-1] = -1;
		}
		for(int i =n-2; i >= 0; i--){
			prefBack[i] = prefBack[i+1] + arr[i];
			larBack[i] = max(prefBack[i],larBack[i+1]);
			smalBack[i] = min(prefBack[i],smalBack[i+1]);
		}
		for(int i = 0; i < m; i++){
			int l,r;
			cin >> l >> r;
			if(l == 1 && r == n){
				cout << "1" << endl;
				continue;
			}
			if(r == n){
				cout <<lar[l-1]-smal[l-1]<<endl;
				continue; 
			}
			if(l == 1){
				cout << larBack[r-1]-smalBack[r-1] << endl;
				continue;
			}
			int lSmall = smal[l-1];
			int lLar = lar[l-1];
			int rSmall = smalBack[r-1];
			int rLar = smalLar[r-1];
			int ans = lLar+rLar-lSmall-rSmall;
			cout << ans << endl;
		}
	}
}