#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define f first
#define s second
vector<pair<long long,int>> v;
long long x[MAXN];
long long a[MAXN];
int arr[MAXN];
long long n,m;
int main(){
	long long t;
	cin >> t;
	while(t--){
		v.clear();
		cin >> n >> m;
		cin >> a[1];
		v.push_back({a[1],1});
		for(int i =2; i <= n; i++){
			cin >> a[i];
			a[i]+=a[i-1];
			v.push_back({a[i],i});
		}
		sort(v.begin(), v.end());
		long long last = a[n];
		long long mx = v[n-1].f;
		arr[n-1] = v[n-1].s;
		for(int i =n-2; i >=0; i--){
			arr[i] = min(arr[i+1],v[i].s);
		}
		for(int i = 0; i < m; i++){
			cin >> x[i];
			if(x[i] > mx && last <= 0){
				cout << "-1 ";
				continue;
			}
			if(x[i] <= mx){
				int cur = lower_bound(v.begin(), v.end(),make_pair(x[i],0))-v.begin();
				cout << arr[cur]-1<<" ";
				continue;
			}
			// cout << " x[i] " << x[i] << " mx " << mx << " last " << last <<endl;
			int cycles = ceil(((double) (x[i]-mx))/((double) last));
			long long lookingfor = x[i]-cycles*last;
			int lb = lower_bound(v.begin(), v.end(),make_pair(lookingfor,0))-v.begin();
			// cout << "cycles: " << cycles << " looking for: " << lookingfor << " lb " <<lb<<endl;
			long long ans = cycles*n+arr[lb]-1;
			cout << ans << " ";

		}
		cout << endl;
	}
}