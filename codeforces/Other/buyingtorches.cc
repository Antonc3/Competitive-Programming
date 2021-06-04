#include <iostream>
#include <math.h>    
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		long long x,y,k;
		cin >> x >> y >> k;
		long long sticksneeded = y*k+k-1;
		long long trades = k+sticksneeded/(x-1);
		if((sticksneeded/(x-1))*(x-1) !=sticksneeded){
			trades++;
		}
		cout << trades <<endl;
	}
}