#include <iostream>

using namespace std;

int main(){
	int arr[5001];
	int n;
	 cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];		
	}
	bool b = false;
	for(int i =1 ; i <= n; i++){
		if(arr[arr[arr[i]]] == i&& arr[arr[i]] != i){
			cout << "YES";
			b = true;
			break;
		}
	}
	if(!b){
		cout << "NO";
	}
}