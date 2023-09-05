#include <bits/stdc++.h>
using namespace std;

int calc(const vector<int> &v,const vector<int> &s){
	int n = v.size();
	int m = s.size();
	vector<int> precalc(n+1);
	int r = m-1;
	for(int i = m-1; i >= 0; i--){
		precalc[i] = precalc[i+1];
		while(r >= 0 && s[r] > a[i]) r--;
		if(r>=0 && v[r] == s[i]) precalc[i]++;
	}
	r = 0;
	int j = 0;
	int ans = 0;
	for(int l =0; l < n; l++){
 		while (j < n && v[j] <= s[l] + j) ++j;
        while (r < m && v[r] - s[l] < j) ++r;
        ans = max(ans, r - l + precalc[j]);
	}
}

void solve(){
	int n,m;
	vector<int>  n1,n2;
	for(int i =0; i < n; i++){
		int a;
		cin >> a;
		if(a > 0) n1.push_back(a);
		else n2.push_back(-a);
	}
	vector<int> s1,s2;
	for(int i =0; i < m; i++){
		int a;
		cin >> a;
		if(a > 0) s1.push_back(a);
		else s2.push_back(-a);
	}
	sort(n2.begin(), n2.end());
	sort(n1.begin(), n1.end());
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	cout << calc(n1,s1) + calc(n2,s2)<<endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}