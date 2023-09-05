#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
int main(){
	int r,g,b;
	cin >> r >> g >> b;
	int colors[3][2000];
	int red[2000]; //0
	int green[2000];//1
	int blue[2000];//2
	priority_queue<pair<int,int>> pq;
	for(int i =0; i < r; i++){
		cin >> colors[0][i];
	}
	for(int i =0; i < g; i++){
		cin >> colors[1][i];
	}
	for(int i =0; i < b; i++){
		cin >> colors[2][i];
	}
	sort(colors[0],colors[0]+r);
	sort(colors[1],colors[1]+g);
	sort(colors[2],colors[2]+b);
	int it[3] = {r-1,g-1,b-1};
	pq.push({colors[0][it[0]],0});
	pq.push({colors[1][it[1]],1});
	pq.push({colors[2][it[2]],2});
	long long int max = 0;
	while(pq.size() > 1){
		pair<int,int> a = pq.top();
		pq.pop();
		pair<int,int> b = pq.top();
		pq.pop();
		max+= a.first*b.first;
		it[a.second]--;
		it[b.second]--;
		if(it[a.second] >=0){
			pq.push({colors[a.second][it[a.second]],a.second});
		}if(it[b.second] >=0){
			pq.push({colors[b.second][it[b.second]],b.second});
		}
	}
	cout << max;
}