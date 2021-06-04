#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
int n;
string s;
//id left/right, no flip or flip
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> s;
		int dpl[n+1];
		int dpr[n+1];
		for(int i = 0; i <= n; i++){
			dpl[i] = i;
			dpr[i] = i;
		}
		for(int i =0; i <= n; i++){
			if(i == 0 || s[i-1] == 'R'){
				continue;
			}
			else if(i == 1 || s[i-2] == 'R'){
				dpl[i] = i-1;
			}
			else{
				dpl[i] = dpl[i-2];
			}
		}

		for(int i =n; i >= =; i--){
			if(i == n || s[i+1] == 'L'){
				continue;
			}
			else if(i == n-1 || s[i+2] == 'L'){
				dpr[i] = i+1;
			}
			else{
				dpr[i] = dpr[i+2];
			}
		}
		for(int i =0; i <=n; i++){
			cout << dpr[i]-dpl[i] << " ";
		}
		cout << endl;
	}
}