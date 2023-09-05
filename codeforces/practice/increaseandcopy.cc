#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int rt = floor(sqrt(n));
		int ans = 0;
		n-=rt;
		while(n > 0){
			n-=rt;
			ans++;
		}
		cout << ans+rt-1<<endl;
	}
}