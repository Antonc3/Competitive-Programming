#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
vector<int> adj[MAXN];
int enjoyment[MAXN];
int n,q;
int main(){
	cin >> n >> q;
	for(int i =1; i <= n; i++){
		cin >> enjoyment[i];
	}
	for(int i =0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}