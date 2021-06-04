#include <queue>
#include <fstream>
#include <vector>

using namespace std;
#define MAXN 505
int n;
int arr[MAXN];
int main(){
	ifstream cin("fcount.in");
	ofstream cout("fcount.out");
	cin >> n;
	for(int i = 0; i <=n; i++){
		cin >> arr[i];
	}
	priority_queue<int> pq;
	vector<int> ans;
	vector<int> add;
	for(int exc =0; exc <=n; exc++){
		for(int i = 0; i <=n; i++){
			if(i != exc) pq.push(arr[i]);
		}
		while(!pq.empty()){
			int cur = pq.top();pq.pop();
			for(int i =0; i < cur; i++){
				if(pq.empty()){
					goto fail;
				}
				int nxt = pq.top();
				pq.pop();
				if(nxt-1>0) add.push_back(nxt-1);
			}
			for(int i : add){
				pq.push(i);
			}
			add.clear();
		}
	
		ans.push_back(exc+1);

		fail:
		while(!pq.empty()) pq.pop();
		add.clear();
	}
	cout << ans.size()<<endl;
	for(int i : ans){
		cout << i<<endl;
	}
}
