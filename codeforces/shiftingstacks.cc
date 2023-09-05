#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long sum = 0;
		bool possible = true;
		for(int i =0; i < n; i++){
			int x;
			cin >> x;
			sum+=x;
			if(sum < (i*(i+1))/2){
				possible = false;
			}
		}
		if(possible){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}