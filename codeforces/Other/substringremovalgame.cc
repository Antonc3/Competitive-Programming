#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool less1(int a, int b){
	return a > b;
}

int main(){
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		string s;
		cin >> s;
		vector<int> islands;
		int cnt = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '1'){
				cnt++;
			}
			else if(cnt > 0){
				islands.push_back(cnt);
				cnt = 0;
			}
		}
		if(cnt > 0){	
			islands.push_back(cnt);
		}
		sort(islands.begin(), islands.end(),less1);
		int ans = 0;
		for(int i = 0; i < islands.size(); i+=2){
			ans += islands[i];
		}
		cout << ans <<endl;
	}
}