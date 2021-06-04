#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 100005
#define f first
#define s second
int n;
int arr[MAXN];
vector<pair<int,int>> sArr;

int binarySearch(int cur){
	int l =0;
	int r = n;
	// cout << "CUR: " <<cur<<"\n\n";
	while(l<=r){
		int m = (l+r)/2;
		// cout << "m: " <<m<<"sArr[].f; " <<sArr[m].f<<endl;
		if(sArr[m].f == cur){
			return m;
		}
		if(sArr[m].f < cur){
			l = m+1;
		}
		else{
			r = m-1;
		}
	}
	return -1;
}

int main(){
	ifstream cin ("csort.in");

	ofstream cout ("csort.out");
	cin >> n;
	int globalMin=99999999;
	for(int i=0; i < n; i++){
		cin >> arr[i];
		sArr.push_back({arr[i],i});
		globalMin = min(globalMin,arr[i]);
	}
	// vector<vector<int>> components;
	vector<bool> used(n,false);
	sort(sArr.begin(), sArr.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		// cout << "ans: " <<ans<<", used[i] " << used[i]<<endl;
		if(used[i]) continue;
		int curPos = binarySearch(arr[i]);
		// cout << "arr[i]: "<<arr[i] << " \n";
		// cout <<"curPos: " << curPos<<endl;
		int curSum = arr[i];
		int curSize = 1;
		used[i]= true;
		int tmpMin = arr[i];
		while(!used[curPos]){
			curSum+=arr[curPos];
			curSize++;
			tmpMin = min(tmpMin,arr[curPos]);
			used[curPos] = true;
			curPos = binarySearch(arr[curPos]);
			// cout << curSize << "\n";
		}
		// cout << "tmpmin: "<<tmpMin <<", curSum: " <<curSum << ", curSize: " <<curSize<<endl;
		if(curSize == 1) continue;
		ans+=(min(curSum+tmpMin*(curSize-2),curSum+globalMin*(curSize+1)+tmpMin));
	}
	cout << ans;
	//2 costs keep minimum cost
}