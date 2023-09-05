#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin >> n>>m;

	int oddK = 0;
	int evenK = 0;
	for(int i = 0; i <n; i++){
		int a;
		cin >> a;
		if(a%2==0) evenK++;
		else oddK++;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int a; 
		cin >> a;
		if(a%2 ==0){
			if(oddK>0){
				ans++;
				oddK--;
			}
		}

		if(a%2 ==1){
			if(evenK>0){
				ans++;
				evenK--;
			}
		}
	}
	cout << ans;

}