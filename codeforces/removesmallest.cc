#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int absi(int a){
	return (a > 0) ? a : -a;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v;
		int curLargest = -1;
		bool ans = true;
		for(int i = 0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		for(int i =1; i <n; i++){
			ans &= (v[i]-v[i-1]<=1);
		}
		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}