#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	for(int c = 0; c < cases; c++){
		string s;
		int x;
		cin >> s >>x;
		string ans;
		int N = s.length();
		for(int i =0; i < N; i++){
			if(i-x >= 0 && s[i-x] =='1'){
				ans+= "1"; 
			}
			else if(i+x < N && s[i+x] == '1'){
				ans+="1";
			}
			else{
				ans+="0"; 
			}
		}
		cout << ans<<endl;
	}
}