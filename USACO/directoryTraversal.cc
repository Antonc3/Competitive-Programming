#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005

vector<int> adj[MAXN];
bool isChild[MAXN];
long long len[MAXN];
int numChildren[MAXN];
long long subTreeLen[MAXN];
long long totalLen[MAXN];
int n;

int totalLeaves = 0;

void dfs(int node){
	numChildren[node] = isChild[node];
	subTreeLen[node] = 0;
	for(int i : adj[node]){
		dfs(i);
		subTreeLen[node] += subTreeLen[i] + numChildren[i]*(len[i] + (isChild[i]) ? 0 : 1);
		numChildren[node] += numChildren[i];
	}
}

void dfs1(int node, long long tot){
	totalLen[node] = tot + subTreeLen[node];
	long long plenadd = 0;
	for(int i : adj[node]){
		plenadd += subTreeLen[i] + numChildren[i] *(len[i]+ (isChild[i] ? 0 : 1));
	}
	for(int i : adj[node]){
		dfs1(i,tot+plenadd-(subTreeLen[i] + numChildren[i]*(len[i] + isChild[i] ? 0:1)) + 3*(totalLeaves-numChildren[i]))
	}
}

int main(){
	cin >> n;
	for(int i =1; i <= n; i++){
		string name;
		int m;
		cin >>name >> m;
		if(m != 0){
			for(int j = 0; j < m; j++){
				int x;
				cin >> x;
				adj[i].push_back(x);
			}
			isChild[i] = false;
		}
		else{
			totalLeaves++;
			isChild[i] = true;
		}
		len[i] = name.length;
	}
	dfs(1);
	dfs1(1,0);
	long long ans = 999999999999999999999999;
	for(int i = 0; i < n; i++){
		if(!isChild[i]){
			ans = min(ans,totalLen[i]);
		}
	}
	cout << ans;
}