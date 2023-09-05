#include <bits/stdc++.h>

using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		int arr[n];
		bool required = false;
		for(int i =0; i < n; i++){
			cin >> arr[i];
			if(arr[i] > d){
				required = true;
			}
		}
		sort(arr,arr+n);
		if(arr[0]+arr[1] <= d || !required){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
}