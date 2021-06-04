#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		int arr[n];
		int arr1[x];
		for(int i =0; i < n; i++){
			cin >> arr[i];
		}
		bool can = true;
		for(int i =0 ; i < n; i++){
			int a;
			cin >> a;
			if(a + arr[n-i-1] > x){
				can = false;
			}
		}
		if(can){
			cout << "Yes"<<endl;
		}
		else{
			cout << "No" << endl;
		}

	}
}