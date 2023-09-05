#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


vector<pair<long long int,long long int>> v[200001];
long long int leaf_nodes[200001];
long long int from[200001];
bool visited[200001];


int N, S;

void dfs(int a){
	visited[a] = true;
	if(v[a].size() == 1){
		leaf_nodes[a] = 1;
	}
	for(pair<long long int, long long int> i : v[a]){
		if(!visited[i.first]){
			dfs(i.first);
			leaf_nodes[a] += leaf_nodes[i.first];
		}
		else{
			from[a] = i.second;
		}
	}

}

long long int solve(){
	dfs(1);
	long long int total = 0;
	priority_queue<pair<long long int, long long int>> pq;
	for(long long int i = 2; i <= N; i++){
		// cout << "i: " << i<< leaf_nodes[i] << ", " << from[i] << endl;
		total += leaf_nodes[i]*from[i];
        long long int diff = (leaf_nodes[i] * from[i]) - (leaf_nodes[i] * (from[i]/2) );
		pq.push({diff,i});
	}
	// cout << "TOTAL: " << total <<endl;
	long long int ans = 0;
	while(total > S){
		ans++;
		pair<long long int, long long int> tp= pq.top();
		pq.pop();
		long long int i = tp.second;
		total-=leaf_nodes[i]*from[i];
		from[tp.second]/=2;
		total+=(leaf_nodes[tp.second]*from[tp.second]);
        long long int new_diff = (leaf_nodes[i] * from[i]) - (leaf_nodes[i] * (from[i]/2) );

		pq.push({new_diff,tp.second});
	}
	return ans;
}

int main(){
	int tc;
	cin >> tc;

	for(int t = 0; t < tc; t++){
		cin >> N >> S;
		for(int i = 0; i < N-1; i++){
			int a, b;
			int cost;
			cin >> a>> b >> cost;

			v[b].push_back({a,cost});
			v[a].push_back({b,cost});
		}
		cout << solve() <<endl;



		for(int i =0 ; i < N+1; i++) v[i].clear();
	    
	    memset(from,0,200000);
	    memset(leaf_nodes,0,200000);
	    memset(visited,false,200000);

	}	
}