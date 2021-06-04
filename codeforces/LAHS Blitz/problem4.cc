#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> arr;
	int n;
	 cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		arr.push_back(a);	
	}
	sort(arr.begin(), arr.end());
	cout << arr[(n-1)/2];
}