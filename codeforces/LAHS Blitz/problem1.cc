#include <iostream>
#include <vector>
using namespace std;

#define ll long long;



int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int mult = 1;
		vector<int> op;
		while(n > 0){
			if(n%10 != 0){
				op.push_back(n%10*mult);
			}
			n/=10;
			mult*=10;
		}
		cout << op.length<<endl;
		for(int i =0 ; i < op.length; i++){
			cout << op[i];
		}
		cout << endl;
	}
}