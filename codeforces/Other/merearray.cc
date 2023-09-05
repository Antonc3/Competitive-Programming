#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
	int cases;
	cin >> cases;
	for(int c = 0; c < cases; c++){
		int N;
		long min = 10000000001;
		cin >> N;
		vector<long> v;
		vector<long> sv;
		for(int i = 0; i < N; i++){
			long num;
			cin >> num;
			min = (min>num) ? num :min;
			v.push_back(num);
			sv.push_back(num);
		}
		bool done =true;
		sort(sv.begin(), sv.end());
		for(int i =0; i < N;i++){
			if(v[i] !=sv[i]){
				if(v[i]%min!=0){
					done = false;
				 	break;
				}
			}
		}
		if(done){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
}