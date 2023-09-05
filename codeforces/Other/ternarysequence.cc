#include <iostream>
using namespace std;

int main(){
	int cases;
	cin >> cases;
	for(int c = 0; c < cases; c++){
		int a0,a1,a2;
		int b0,b1,b2;
		cin >> a0>>a1>>a2;
		cin >>b0>>b1>>b2;
		int result = 0;
		result = min(a2,b1)*2;
		b1-=result/2;
		a2-=result/2;
		b2-=a2;
		b2-=min(a0,b2);
		if(b2>0){
			result-=b2*2;
		}
		cout << result << endl;
	}
}