#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int arr[MAXN];
multiset<int> s;
int n,k;
int main(){
	cin >> n >> k;
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < k; i++){
		s.insert(arr[i]);
	}
	int ans = 0;
	for(int i = k; i < n; i++){
		auto mid = s.cbegin();
		advance(mid,(k)/2);
		ans = max(ans,*(mid));
		// cout << "ans, mid " << ans << ", " << *mid<< " s.size " << s.size()<<endl;

		auto it = s.find(arr[i-k]);
		s.erase(it);
		s.insert(arr[i]);
	}
	cout << ans;
}