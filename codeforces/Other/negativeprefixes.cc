#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool greaterTh(int a, int b){
	return a>b;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> v;
		vector<int> locked;

		int n;
		cin >> n;
		for(int i =0; i < n; i++){
			int a;
			cin >> a;
			v.push_back(a);
		}for(int i =0; i < n; i++){
			int a;
			cin >> a;
			locked.push_back(a);
		}
		vector<int> unlocked;
		for(int i =0; i < n; i++){
			if(locked[i] ==0){
				unlocked.push_back(v[i]);
			}
		}
		sort(unlocked.begin(), unlocked.end(),greaterTh);
		int cnt = 0;
		for(int i =0; i < n; i++){
			if(locked[i] == 0){
				cout << unlocked[cnt]<<" ";
				cnt++;
			}
			else{
				cout << v[i] << " ";
			}
		}
		cout << endl;
	}
}