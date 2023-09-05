#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005

int n;
int arr[MAXN];
int fz[MAXN];
int main(){
	cin >> n;
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}

	fz[n-1] = (arr[n-1] == 0) ? 1 : 0;
	for(int i = n-2; i >= 0; i--){
		if(arr[i] == 0){
			fz[i] = fz[i+1] + 1;
		}
		else{
			fz[i] = 0;
		}
	}
	if(arr[n-1] == 0){
		fz[n-1] = fz[0]+1;
	}
	for(int i =0; i < n; i++){
		cout << fz[i] << " ";
	}
	cout << endl;
	// int totalEnergy = 0;
	// for(int i = 0; i < n; i++){
	// 	int cur = i;
	// 	int nxt = (i+1)%n;
	// 	int dist = 0
	// 	while(arr[nxt] == 0 && arr[cur] > 0){
	// 		arr[cur]--;
	// 		arr[nxt]++;
	// 		dist++;
	// 		cur=nxt;
	// 		nxt=(nxt+1)%n;
	// 	}
	// 	totalEnergy+=dist*dist;
	// }
}