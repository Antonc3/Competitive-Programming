#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
int n;
vector<int> childSize[MAXN];
int size[MAXN];
void dfs(int cur,int par){
	size[cur] = 1;
	for(int i : adj[cur]){
		if(i != par){
			dfs(i,cur);
			size[cur]+=size[i];
			childSize[cur].push_back(size[i]);	
		}
	}
	if(size[cur] != n) childSize[cur].push_back(n-size[cur]);
}
int cur[MAXN];
bool solve(int k){
	if((n-1)%k != 0) return 0;
	for(int i =0; i <=n; i++) cur[i] = 0;
	for(int i =1; i<=n;i++){
		int cnt =0;
		for(int a : childSize[i]){
			a%=k; 
			if(a==0) continue;
			if(cur[k-a] > 0){
				cur[k-a]--;
				cnt--;
			}
			else{
				cur[a]++;
				cnt++;
			}
		}
		if(cnt != 0) return 0;
	}
	return 1;
}

int main(){
	ifstream cin("deleg.in");
	ofstream cout("deleg.out");
	cin >> n;
	for(int i =0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,-1);
	for(int i =1; i < n; i++){
		cout << solve(i);
	}
}