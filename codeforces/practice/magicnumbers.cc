#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	bool isMag = true;
	int num4s = 0;
	while(n > 0){
		int cur = n%10;
		if(cur != 4 && cur != 1){
			isMag = false;
			break;
		}
		if(cur == 4){
			num4s++;
		}
		if(num4s > 2){
			isMag = false;
			break;
		}
		if(cur == 1){
			num4s = 0;
		}
		n/=10;
	}
	if(num4s != 0){
		isMag = false;
	}
	if(isMag){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
}