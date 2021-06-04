#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
vector<int> arr[MAXN];
int n, base[MAXN];
int main(){
	cin >> n;
	int placed = 0, ans = n;
	for(int i =0; i < n; i++){
		int x; cin >> x;
		if(x < placed){
			ans = i;
			break;
		}
		for(int j = x; j > 0 && !base[j]; j--){
			base[j] = x;
		}
		while(!arr[base[x]].empty() && arr[base[x]].back() < x){
			placed = arr[base[x]].back();
			arr[base[x]].pop_back();
		}
		arr[base[x]].push_back(x);
	}
	cout << ans << endl;
}