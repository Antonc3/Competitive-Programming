#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 1000005
#define f first
#define s second
vector<pair<int,int>> adj[MAXN];
int n,m;
vector<bool> visited(MAXN,false);
int MOD = 1e9+7;
int dfs(int n){
	int nodes = 0;
	// int edges =0;
	stack<pair<int,int>> s;
	visited[n] = true;
	s.push({n,-1});
	bool cycle = false;
	// cout << " DFS \n nodes: "; 
	while(!s.empty()){
		pair<int,int> t = s.top();
		s.pop();
		// cout << t.f << "\n";
		nodes++;
		for(pair<int,int> i : adj[t.f]){
			// cout << "cur: " << i.f << ", " << i.s << endl;
			if(t.s == i.s) continue;
			// cout << "made it past1 "<< i.f << ", " << i.s << endl;
			if(visited[i.f]) {
				cycle = true;
				continue;
			}
			// cout << "made it past "<< i.f << ", " << i.s << endl;
			visited[i.f] = true;
			s.push({i.f,i.s});
		}
	}
	// cout << "\nNODES: " << nodes<<endl;
	// cout << "CYCLEL " << cycle<<endl;
	// cout << endl;
	return (cycle) ? 2 : nodes;
}

int main(){

	ifstream cin ("alliance.in");

	ofstream cout ("alliance.out");
	cin >> n >> m;
	for(int i =0; i < m; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
	}

	//dfs now
	long long ans = 1;
	for(int i =1; i <= n; i++){
		// cout << " visited[i] " << visited[i] << endl;
		if(!visited[i]){
			// cout << dfs(i) << endl;
			ans *= dfs(i);
			ans%=MOD;
		}
		// cout << endl;
	}
	cout << ans;
}