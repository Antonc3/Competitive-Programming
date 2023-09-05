#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
int n,m;

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		map<int,int> mp;
		for(int i=0; i < n; i++){
			int x,y;
			cin >> y >> x;
			mp[x] += y;
		}
		mp[n+1] = 3;
		int lastX = 0;
		int half = 0;
		bool done = false;
		for(auto[x,mask] : mp){
			if(mask != 3){
				//either 1 or 2
				if(half){
					int dif = x-lastX;
					if(dif%2==0 && half != mask){
						done = true;
						cout << "NO\n";
						break;
					}
					if(dif%2 && half == mask){
						done = true;
						cout << "NO\n";
						break;
					}
					half = 0;
					lastX = x;
				}
				else{
					half = mask;
					lastX = x;
				}
			}
			else{
				if(half){
					cout << "NO\n";
					done = true;
					break;
				}
				lastX = x;
			}
		}
		if(!done){
			cout << "YES\n";
		}
	}
	
}