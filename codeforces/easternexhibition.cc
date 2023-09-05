#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define f first
#define s second
pair<int,int> a[MAXN];
int n;
int absi(int x){
	return (x > 0) ? x : -x;
}
int dist(pair<int,int> a,pair<int,int> b){
	return (absi(a.f-b.f)+absi(a.s-b.s));
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i =0; i < n; i++){
			cin >> a[i].f >> a[i].s;
		}
		long long mn = 12312312321123123;
		int ans = 0;
		for(int i =0; i < n; i++){
			long long cur = 0;
			for(int j = 0; j < n; j++){
				cur += dist(a[i],a[j]);
			}
			if(cur == mn){
				ans++;
			}
			else if(cur < mn){
				ans = 0;
				mn = cur;
			}
		}
		cout << ans<<endl;
	}
}