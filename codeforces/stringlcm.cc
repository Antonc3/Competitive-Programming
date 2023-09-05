#include <bits/stdc++.h>
using namespace std;

bool checkMult(string s,int len){
	int strLen = s.size();
	if(strLen%len != 0 || len > strLen){
		return false;
	}
	if(len == strLen){
		return true;
	}
	int numSections = strLen/len;
	for(int i = 0; i < strLen; i+=len){
		
		for(int j =0; j < len; j++){
			if(s[j] != s[i+j]){
				return false;
			}
		}
	}
	return true;
}
int gcd(int a,int b){
	if(b == 0){
		return a;
	}
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return (a/gcd(a,b))*b;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string s1,s2;
		cin >> s1 >>s2;
		bool hasmult = false;
		int smol = 0;
		for(int i =1; i <= 20; i++){
			bool has1 = checkMult(s1,i);
			bool has2 = checkMult(s2,i);
			if(has1 && has2){
				if(s1.substr(0,i).compare(s2.substr(0,i)) == 0){
					hasmult = true;
					smol  = i;;
					break;
				}
			}
		}
		if(!hasmult){
			cout << "-1"<<endl;
		}
		else{
			int sLcm = lcm(s1.size()/smol,s2.size()/smol);
			for(int i =0; i < sLcm; i++){
				cout << s1.substr(0,smol);
			}
			cout << endl;
		}
	}
}