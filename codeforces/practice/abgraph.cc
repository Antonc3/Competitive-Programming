#include <bits/stdc++.h>

using namespace std;
#define MAXN 1005
int n,m;
int grid[MAXN][MAXN];
int has[MAXN][2];
void solve(){
	cin >> n >> m;
	for(int i =0; i < n; i++){
		has[i][0] = has[i][1] = -1;
	}
	for(int i=0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			if(i==j) continue;
			grid[i][j] = c-'a';
			has[i][grid[i][j]] = j;
		}
	}
	if(m&1){
		cout << "YES\n";
		for(int i =0; i < m+1; i++){
			cout << i%2+1 <<" ";
		}
		cout << "\n";
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j =i+1; j < n; j++){
			if(grid[i][j] == grid[j][i]){
				cout << "YES\n";
				for(int k = 0; k < m+1; k++){
					cout << ((k&1) ? i+1 : j+1) << " ";
				}
				cout << "\n";
				return;
			}
		}
	}
	for(int i =0; i < n; i++){
		for(int j =0 ; j < n; j++){
			if(i == j) continue;
			if(has[j][grid[i][j]] == -1) continue;
			cout << "YES\n";
			int cur = has[j][grid[i][j]];
			if((m/2)%2 == 1){
				for(int k =0; k < m+1; k++){
					if(k%4 == 0){
						cout << i+1 << " ";
					}
					else if(k%2 == 0){
						cout << cur+1 << " ";
					}
					else{
						cout << j+1<<" ";
					}
				}
				cout << "\n";
				return;
			}
			for(int k =0; k < m+1; k++){
				if(k%2==0){
					cout << j+1 << " ";
				}
				else if(k%4 == 1){
					cout << cur+1 << " ";
				}
				else{
					cout << i+1 << " ";
				}
			}
			cout << "\n";
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	int t; cin >> t;
	while(t--){
		solve();
	}
}