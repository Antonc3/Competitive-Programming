#include <iostream>

using namespace std;

long long int getSum(long long int i){
	int sum = 0;
	while(i>0){
		sum+= i%10;
		i/=10;
	}
	return sum;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long long int num;
		int s;
		cin >> num >> s;
		long long int ans = 0;
		long long int mult = 1;
		while(getSum(num) > s){
			int cur = num%10;
			ans += (10-cur)*mult;
			num/=10;
			num++;
			mult*=10;
		}
		cout << ans <<endl;
	}
}