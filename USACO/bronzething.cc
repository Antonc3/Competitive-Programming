#include <bits/stdc++.h>

using namespace std;
#define s second
#define f first
vector<pair<int,pair<int,int>>> east;
vector<pair<int,pair<int,int>>> north;
vector<pair<char,pair<int,int>>> all;

int n;

int main(){
	cin >> n;

	for(int i =0; i < n; i++){
		char c; 
		int a,b;
		cin >> c >> a >> b;
		if(c == 'E'){
			east.push_back({i,{a,b}});
		}
		else{
			north.push_back({i,{a,b}});
		}
		all.push_back({c,{a,b}});
	}
	vector<pair<int,pair<int,int>>> collisions;
	for(int i =0; i < east.size(); i++){
		auto cur = east[i];
		for(int j = 0; j < north.size(); j++){
			auto compare = north[j];
			if(compare.s.s > cur.s.s) continue;
			if(cur.s.f > compare.s.f) continue;
			if(compare.s.f-cur.s.f+compare.s.s <cur.s.s) continue;
			collisions.push_back({compare.s.f-cur.s.f,{cur.f,compare.f}});
		}
	}
	for(int i =0; i < north.size(); i++){
		auto cur = north[i];
		for(int j = 0; j < east.size(); j++){
			auto compare = east[j];
			if(compare.s.s < cur.s.s) continue;
			if(cur.s.f < compare.s.f) continue;
			if(compare.s.s-cur.s.s+compare.s.f <cur.s.f) continue;
			collisions.push_back({compare.s.s-cur.s.s,{cur.f,compare.f}});
		}
	}
	sort(collisions.begin(), collisions.end());
	vector<int> ans(n,-1);
	vector<pair<int,pair<int,int>>> sameTime;
	int lastTime = -1;
	for(int i =0; i <collisions.size(); i++){
		auto cur = collisions[i];
		lastTime = cur.f;
		int aa = i;
		while(lastTime == cur.f && aa < collisions.size()){
			cur = collisions[aa];
			aa++;
			sameTime.push_back(cur);
		}
		i = aa-1;
		bool same[sameTime.size()];

		for(int j = 0; j < sameTime.size(); j++){
			for(int k = 0; k < sameTime.size(); k++){
				if(j == k) continue;
				auto a = sameTime[j];
				auto b = sameTime[k];
				if(a.s.s == b.s.f && a.s.f == b.s.s){
					same[j] = true;
					same[k] = true;
				}
			}
		}

		for(int j = 0; j < sameTime.size(); j++){
			if(same[j]) continue;
			cur = sameTime[j];
			if(ans[cur.s.f] != -1) continue;
			auto fir = all[cur.s.f];
			auto sec = all[cur.s.s];
			if(sec.f == 'N'){
				// s cow going north f going east
				if(fir.s.s > sec.s.s + ans[cur.s.s] && ans[cur.s.s] != -1) continue;
			}
			else{
				// s cow going north f going east
				if(fir.s.f > sec.s.f + ans[cur.s.s] && ans[cur.s.s] != -1) continue;
			}
			
			ans[cur.s.f] = cur.f;
		}
		
	}
	for(int i= 0; i < n; i++){
		if(ans[i] == -1) cout << "Infinity";
		else{
			cout << ans[i];
		}
		cout << endl;
	}
}