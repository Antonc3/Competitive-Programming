#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

void solve(){
	vector<pair<int,int>> h,w;
	int n;
	cin >> n;
	pair<int,int> ppl[n+1];
	for(int i =1; i <=n; i++){
		int a,b;
		cin >> a >> b;
		if(a > b){
			swap(a,b);
		}
		ppl[i] = {a,b};
		h.push_back({a,i});
		w.push_back({b,i});
	}
	sort(h.begin(), h.end());
	sort(w.begin(), w.end());
	// for(auto i : h){
	// 	cout << i.f << ", " << i.s<<endl;
	// }
	// cout <<"w: "<<endl;
	// for(auto i : w){
	// 	cout << i.f << ", " << i.s<<endl;
	// }
	bool seen[n+1];
	fill(seen, seen+n+1, false);
	int ans[n+1];
	while(h.size()){
		auto cur = h.back();
		h.pop_back();
		int curi = cur.s;
		queue<int> eql;
		eql.push(curi);
		seen[curi] = true;
		while(h.size() && h.back().f == cur.f){
			eql.push(h.back().s);
			seen[h.back().s] = true;
			h.pop_back();
		}
		
		while(eql.size()){
			int tp = eql.front();
			eql.pop();
			int curw = ppl[tp].s;
			while(w.size() && seen[(*w.begin()).s]){
				w.erase(w.begin());
			}
			if(w.empty() || (*w.begin()).f  >= curw) {
				ans[tp] = -1;
			}
			else{
				ans[tp] = (*w.begin()).s;
			}
		}
		
	}	
	for(int i =1; i <=n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}