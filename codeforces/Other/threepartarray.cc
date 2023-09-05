#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	long arr[N];
	for(int i =0; i < N; i++){
		cin >> arr[i];
		
	}
	if(N < 2){
		cout << "0";
	}
	else {
		long long max = 0;
		int i1 = 0;
		int i2 = N-1;
		long long v1 = arr[i1];
		long long v2 = arr[i2];
		while(i1<i2){
			if(v1 == v2){
				max = v1;
				i1++;
				v1+=arr[i1];
				i2--;
				v2+=arr[i2];
			}
			else if(v1>v2){
				i2--;
				v2+=arr[i2];
			} 
			else if(v1 <v2){
				i1++;
				v1+=arr[i1];
			}
		}
		
		cout << max;
	}
}