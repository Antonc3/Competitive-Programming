#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
int arr[MAXN];
int n,k,l;
bool possible(int a){
	long long left = k*l;
	for(int i = n-1; i >= n-a; i--){
		if(arr[i]-a >= 0) continue;
		if(a-arr[i] > k)return false;
		if(a-arr[i] > left) return false;
		left-=(a-arr[i]);
	}
	return true;
}
int main(){
	cin >> n >> k >> l;
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	int l = 0, r = n;
	while(l < r){
		int m = (l+r)/2;
		if(possible(m)){
			l = m+1;
		}
		else {
			r = m-1;
		}
		cout << l << " " <<r <<" "<< m<<endl;
	}
	cout << l-1;
}