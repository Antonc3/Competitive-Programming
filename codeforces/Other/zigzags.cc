#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct pair1 {
	int i;
	int val;
	pair1(int i, int val) : i(i), val(val){

	}
};

bool compareVal(pair1 a, pair1 b){
	return a.val > b.val;
}

bool compareI(pair1 a, pair1 b){
	return a.i < b.i;
}

int main() {
	int tc;
	cin >> tc;
	cout << endl;
	for(int t = 0; t < tc; t++){
		int N;
		cin >> N;
		vector<int> inf;
		for(int i = 0; i < N; i++){
			int val;
			cin >> val;
			inf.push_back(val);
		}
		map<int, int> jVal;
		int j = 0;
		int k = N-1;
		bool i = false;
		long long  tuples = 0;
		for(int j = 0; j < N; j++){
			map<int, int> kVal;
			int n1 = inf[j];
			for(int k = N-1; k > j; k--){
				int n2 = inf[k];
				tuples+=(jVal[n2] * kVal[n1]);
				kVal[n2]++;
			}
			jVal[n1]++;
		}
		cout << tuples <<endl;
	}
}