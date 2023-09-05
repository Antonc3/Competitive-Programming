// #include <bits/stdc++.h>
// using namespace std;
// #define MAXN 100005
// #define MAXK 200005

// int n,k;
// long long m;
// int swaps[2][MAXK];
// int cnt[MAXN];
// bool donelay[MAXN];

// set<int> visited[MAXN][61];
// int arr[MAXN][61];
// set<int> ans[MAXN];
// int sze[MAXN][61];
// set<int> curVis[MAXN];
// int curPos[MAXN];
// bool done[MAXN];
// void mv(int lay){
// 	int tmp[n+1];
// 	int tmpPos[n+1];
// 	for(int i =1; i <= n; i++){
// 		tmpPos[i] = curPos[i];
// 		tmp[arr[i][lay]] = i;
// 	}
// 	for(int i =1; i<=n; i++){
// 		//looking at pos i
// 		curPos[tmp[i]] = tmpPos[i];
// 		if(done[tmpPos[i]]){
// 			continue;
// 		} 
// 		int curSize = curVis[tmpPos[i]].size();
// 		curVis[tmpPos[i]].insert(visited[i][lay].begin(),visited[i][lay].end());
// 		if(curVis[tmpPos[i]].size() == curSize){
// 			done[tmpPos[i]] = true;
// 		}
// 	}
// }

// void createLay(int lay){
// 	int prev = lay-1;
// 	int tmp[n+1];
// 	for(int i =1; i <= n; i++){
// 		tmp[arr[i][prev]] = i;
// 	}
// 	for(int i=1; i <= n; i++){
// 		arr[tmp[i]][lay] = arr[i][prev];
// 		if(sze[arr[i][prev]][prev] == sze[arr[i][prev]][prev-1]){
// 			sze[arr[i][prev]][lay] = sze[arr[i][prev]][prev];
// 			visited[arr[i][prev]][lay] = visited[arr[i][prev]][prev];
// 			continue;
// 		}
// 		set<int> cur = visited[arr[i][prev]][prev];
// 		int csize = cur.size();
// 		cur.insert(visited[i][prev].begin(), visited[i][prev].end());
// 		if(cur.size() == csize){
// 			sze[arr[i][prev]][lay] = sze[arr[i][prev]][prev];
// 			visited[arr[i][prev]][lay] = visited[arr[i][prev]][prev];
// 			continue; 
// 		}
// 		visited[arr[i][prev]][lay] = cur;
// 		sze[arr[i][prev]][lay] = cur.size();
// 	}
// }

// void createArr(){
// 	for(int i =2; i <61; i++){
// 		createLay(i);
// 	}
// }



// void swap(int a,int b,int la){
// 	int tmp = arr[a][la];
// 	arr[a][la] = arr[b][la];
// 	arr[b][la] = arr[a][la];
// }
// int main(){
// 	cin >> n >> k >> m;
// 	// d.init(n+1);
// 	for(int i=1; i <= n; i++){
// 		arr[i][0] = i;
// 		arr[i][1] = i;
// 		visited[i][0].insert(i);
// 		visited[i][1].insert(i);
// 		curPos[i] = i;
// 		done[i] = false;
// 	}
// 	bool done = false;
// 	for(int i =0; i < k; i++){
// 		if(m <= k){
// 			done =true;
// 			break;
// 		}
// 		int a,b;
// 		cin >> a >> b;
// 		swaps[0][i] = a;
// 		swaps[1][i] = b;
// 		visited[arr[a][1]][1].insert(b);
// 		visited[arr[b][1]][1].insert(a);
// 		swap(a,b,1);

// 		// d.unite(swaps[0][i],swaps[1][i]);
// 	}
// 	// if(done){
// 	// 	for(int i=1; i <= n; i){
// 	// 		cout<<visited[i][1].size();
// 	// 	}
// 	// }

// 	long long tl = m/((long long) k);
// 	long long power2[61];
// 	power2[0] = 1;
// 	for(int i = 1; i < 61; i++){
// 		power2[i] = power2[i-1]*2;
// 	}
// 	int cur = 55;
// 	while(cur >= 0){
// 		if(tl > power2[cur]){
// 			mv(cur+1);
// 			tl-=power2[cur];
// 		}
// 		cur--;
// 	}
// 	int left = m%k;
// 	for(int i =0; i < left; i++){

// 		int a = swaps[0][i];
// 		int b = swaps[1][i];
// 		curVis[curPos[a]].insert(b);
// 		curVis[curPos[b]].insert(a);
// 		swap(a,b,1);
// 	}
// 	for(int i = 1; i<=n; i++){
// 		cout << curVis[i].size()<<endl;
// 	}
// 	// bool needhelp = false;
// 	// for(int i =1; i <=n; i++){
// 	// 	ans[i] = 1;
// 	// 	long long cur =(long long) d.size(i);
// 	// 	if(cur*cur <= m){
// 	// 		ans[i] = cur;
// 	// 	}
// 	// 	else{
// 	// 		ndhelp[i] = true;
// 	// 		needhelp = true; 
// 	// 	}
// 	// }
// }

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXK 200005
#define f first
#define s second
int A[MAXK],B[MAXK];
int P[MAXN],from[MAXN];
int N,K;
long long M;
vector<pair<int,int>> S[MAXN];
int cnt[MAXN];
bool visited[MAXN];
vector<int> nodes;
int uniquePos;
void add(int node,int mx){
	for(auto a : S[node]){
		if(a.s > mx) return;
		if(cnt[a.f] == 0){
			uniquePos++;
		}
		cnt[a.f]++;
	}
}
void remove(int node,int mx){
	for(auto a : S[node]){
		if(a.s > mx) return;
		if(cnt[a.f] == 1){
			uniquePos--;
		}
		cnt[a.f]--;
	}
}
void dfs(int node){
	visited[node] = true;
	nodes.push_back(node);
	if(!visited[P[node]])
		dfs(P[node]);
}
int main(){
	cin >> N >> K >> M;
	for(int i =0; i < K; i++){
		cin >> A[i] >> B[i];
	}
	for(int i =1; i <= N; i++){
		from[i] = i;
		S[i].push_back({i,0});
	}
	for(int i =0; i < K;i++){
		S[from[A[i]]].push_back({B[i],i+1});
		S[from[B[i]]].push_back({A[i],i+1});
		swap(from[A[i]],from[B[i]]);
	}
	for(int i =1; i <= N; i++){
		P[from[i]]=i;
	}
	int ans[MAXN];
	for(int i = 1; i <=N; i++){
		if(!visited[i]){
			dfs(i);
			long long D = M/K;
			int R = M%K;
			if(D >= (int) nodes.size()){
				D = nodes.size();
				R = 0;
			}
			for(int j = 0; j < D; j++){
				add(nodes[j],K);
			}
			int j = D-1;
			for(int i = 0; i <nodes.size(); i++){
				int nxt = (j+1)%(int) nodes.size();
				add(nodes[nxt],R);
				ans[nodes[i]] = uniquePos;
				remove(nodes[nxt],R);
				remove(nodes[i],K);
				add(nodes[nxt],K);
				j = nxt;
			}
			for (int k=0;k<=D-1;k++)
				remove(nodes[k],K);
	      	nodes.clear();
		}
	}
	for(int i = 1; i <= N; i++){
		cout << ans[i]<<endl;
	}
	return 0;
}