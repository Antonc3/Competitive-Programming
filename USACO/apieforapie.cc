#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define f first
#define s second
typedef  pair<int,int> pii;

int a[MAXN*2];
int b[MAXN*2];

struct cmpA
{
	bool operator()(int aa,int bb) const
	{
		return b[aa]<b[bb];
	}
};
 
struct cmpB
{
	bool operator()(int aa,int bb) const
	{
		return a[aa]<a[bb];
	}
};
multiset<int,cmpA> a1;
multiset<int,cmpB> b1;
multiset<pair<int,pii>> bes;
multiset<pair<int,pii>> els;
int n,d;
int dist[MAXN*2];


int main(){
	freopen("piepie.in","r",stdin);
	freopen("piepie.out","w",stdout);
	cin >> n >> d;
	//dont even need a pq
	queue<int> q;
	for(int i =0; i <2*n; i++){
		cin >> a[i] >> b[i];
		a[i] = -a[i]; b[i] = -b[i];
		dist[i] = -1;
	}
	for(int i =0; i < n; i++){
		if(b[i] == 0){
			q.push(i); dist[i] = 1;
		}
		else{
			a1.insert(i);
		}
		if(a[i+n] == 0){
			q.push(i+n); dist[i+n] = 1;
		}
		else{
			b1.insert(i+n);
		}
	}
	// for(int i =0; i < n; i++){
	// 	pair<int,pii> tmp;
	// 	cin >> tmp.f >> tmp.s.f;
	// 	tmp.s.s = i;
	// 	dist[i] = -1;
	// 	if(tmp.s.f == 0){
	// 		q.push({tmp.f,i});
	// 		dist[i] =1;
	// 	}
	// 	else{
	// 		bes.insert(tmp);
	// 	}
	// }
	// for(int i =n; i <2* n; i++){
	// 	pair<int,pii> tmp;
	// 	cin >> tmp.s.f >> tmp.f;
	// 	tmp.s.s = i;
	// 	dist[i] = -1;
	// 	if(tmp.s.f == 0){
	// 		q.push({tmp.f,i});
	// 		dist[i] =1;
	// 	}
	// 	else{
	// 		els.insert(tmp);
	// 	}	
	// }
	//bfs
	while(!q.empty()){
		//first is tasty value
		//second is i
		int cur = q.front();
		// cout << cur.f << ", " << cur.s << endl;
		q.pop();
		if(cur >= n){
			while(1){
				// auto it = bes.lower_bound(make_pair(cur.f-d,make_pair(0,0)));
				auto it = a1.lower_bound(cur);
				if(it == a1.end() || b[(*it)] > b[cur]+d){
					break;
				}
				dist[*it] = dist[cur]+1;
				q.push(*it);
				a1.erase(it);
				
			}
		}
		else{
			while(1){
				auto it = b1.lower_bound(cur);
				if(it == b1.end() || a[(*it)] > a[cur]+d){
					break;
				}
				dist[*it] = dist[cur]+1;
				q.push(*it);
				b1.erase(it);
			}
		}
	}
	for(int i =0; i < n; i++){
		cout << dist[i] << endl;
	}
}