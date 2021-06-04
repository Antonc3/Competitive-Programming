#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
long long n;
int inc_exc[] = {0,1,-1,1,-1,1,-1};
struct s5 {
	int n;
	int v[5];
};
bool operator< (const s5 &a, const s5 &b){
	for(int i=0; i < 5; i++){
		if(a.v[i] < b.v[i]) return true;
		if(a.v[i] > b.v[i]) return false;
	}
	return false;
}
map<s5,int> m;

s5 getSubset(s5 a,int x){
	s5 cur= {0,{0,0,0,0,0}};
	for(int i =0; i < 5; i++){
		if((1<<i) & x){
			cur.v[cur.n++] = a.v[i];
		}
	}
	return cur;
}

int main(){
	cin >> n;
	for(int i =0; i < n; i++){
		s5 cur;
		for(int i =0; i < 5; i++){
			cin >> cur.v[i];
		}
		// cin >> cur.v[0] >> cur.v[1] >> cur.v[2] >> cur.v[3] >> cur.v[4];
		sort(cur.v,cur.v+5);
		for(int i = 1; i < 31; i++){
			s5 nxt = getSubset(cur,i);
			m[nxt]++;
		}
	}
	long long ans = n*(n-1)/2;
	for(auto p : m){
		ans-=p.second*inc_exc[p.first.n]*(p.second-1)/2;
	}
	cout << ans;
}