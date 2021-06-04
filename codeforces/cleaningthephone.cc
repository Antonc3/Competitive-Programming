#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> i1;
		vector<int> i2;
		int n,m;
		cin >> n >> m;
		int arr[n];
		for(int i =0; i < n; i++){
			cin >> arr[i];
		}
		for(int i =0; i < n; i++){
			int x;
			cin >> x;
			if(x == 1){
				i1.push_back(arr[i]);
			}
			else{
				i2.push_back(arr[i]);
			}
		}
		sort(i1.begin(), i1.end());
		sort(i2.begin(), i2.end());
		int ii1 = i1.size()-1;
		int ii2 = i2.size()-1;
		int curm = 0;
		int curImportance = 0;
		while(curm < m &&(ii1 >= 0 || ii2>=0)){

			int curi1 = (ii1 >= 0) ? i1[ii1] : 0;
			int curi2 = (ii2 >= 0) ? i2[ii2] : 0;
			int nxti1 = (ii1-1 >= 0) ? i1[ii1-1] : 0;
			// cout << "m: " << curm << ", " << ii1 << ", " << ii2 << endl;
			// cout << "curi1: " << curi1 << " curi2 " << curi2 << " nxti1 " << nxti1	<<endl;
			if(curi1 + nxti1 > curi2 || curm+curi1 >= m || ii2 < 0){
				curm+=curi1;
				curImportance++;
				ii1--;
			}
			else{
				curImportance+=2;
				curm+=curi2;
				ii2--;
			}
		}
		if(curm < m){
			cout << "-1\n";
		}
		else{
			cout << curImportance<<"\n";
		}
	}
}