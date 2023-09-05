#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int num3s=0;
		int a = n;

		while(a%3 == 0){
			num3s++;
			a/=3;
		}
		a = n;
		int ans = 0;
		while(num3s > 0){
			if(a%6 == 0){
				a/=6;
				num3s--;
			}
			else{
				a*=2;
			}
			ans++;
		}
		if(a == 1){
			cout << ans << endl;
		}
		else{
			cout << "-1" << endl;
		}
	}
}