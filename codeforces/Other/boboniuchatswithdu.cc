#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool greaterThan(int a, int b){
	return a>b;
}
int main(){
    int n,d;
	long long int m;
	cin >> n>>d>>m;
	vector<long long int> big;
	vector<long long int> small;
	for(int i =0; i< n; i++){
		long long int in;
		cin >> in;
		if(in > m){
			big.push_back(in);
		}
		else{
			small.push_back(in);
		}
	}
	
	sort(big.begin(), big.end(), greaterThan);
	
	sort(small.begin(), small.end(),greaterThan);
	long long int bigArr[100005];
	long long int smallArr[100005];
	bigArr[0] = 0;
	smallArr[0] =0;
	for(int i = 0; i < big.size(); i++){
		bigArr[i+1] = bigArr[i]+big[i];
	}
	for(int i = 0; i < small.size(); i++){
		smallArr[i+1] = smallArr[i]+small[i];
	}

	long long int ma = 0;
	int b =0;
    int sSize = small.size();
	while(b <= big.size()){
	    int a = (b-1 > 0) ? b-1 : 0;
	    int movesUsed = a*(d+1) + (b>=1);
	    if(movesUsed > n){		
	    	break;
	    }
		int s = max(0,min(n-movesUsed,sSize));
		ma = max(ma, bigArr[b] + smallArr[s]);
        b++;
	}
	cout << ma;
}