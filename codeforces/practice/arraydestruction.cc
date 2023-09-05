#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> check(vector<int> aa, int x){
	int last = x;
	vector<int> v;
	v.insert(v.end(),aa.begin(), aa.end());
	vector<int> ans;
	for(int i = 0; i < n; i++){
		int cur = v.back();
		v.pop_back();
		auto nxt = lower_bound(v.begin(),v.end(),last-cur);
		if(cur + *nxt == last&& nxt != v.end()){
			ans.push_back(*nxt);
			ans.push_back(cur);
		}
		else{
			return {};
		}
		v.erase(nxt);
		last = cur;
	}
	return ans;
}
void solve(){
	cin >> n;
	vector<int> v;
	for(int i =0; i < 2*n; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	for(int i = 0; i < 2*n-1; i++){
		int x = v[i] + v.back();
		vector<int> ans = check(v,x);
		if(ans.size()){
			cout << "YES\n"<<ans[0] + ans[1]<<"\n";
			for(int i = 0; i < ans.size(); i+=2){
				cout << ans[i] << " " << ans[i+1]<<"\n";
			}
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}