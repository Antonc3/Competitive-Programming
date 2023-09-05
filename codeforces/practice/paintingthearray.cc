#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
int a[MAXN];
int n;
int pos[MAXN], nxt[MAXN];
vector<int> v;
int main(){
	cin >> n;
	for(int i =1; i <= n; i++){
		cin >> a[i];
	}
	for(int i =0; i <= n; i++){
		pos[i] = n+1;
	}
	for(int i = n; i >= 0; i--){
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	int ans = 0;
	int x = 0, y = 0;
	for(int i =1; i <= n; i++){
		if(a[x] == a[i]){
			ans += (a[y] != a[i]);
			y = i;
		}
		else if(a[y] == a[i]){
			ans+= (a[x] != a[i]);
			x = i;
		}
		else if (nxt[x] < nxt[i])
		{
			res += a[x] != a[i];
			x = i;
		}
		else
		{
			res += a[y] != a[i];
			y= i;
		}
	}
	cout << ans;
}