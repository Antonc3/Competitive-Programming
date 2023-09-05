#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	long long int arr[N];
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	if(N == 1){
		cout << "1 1" <<endl;
		cout << 0 << endl;
		cout << "1 1" <<endl;
		cout << 0 << endl;
		cout << "1 1" <<endl;
		cout << -arr[0] << endl;
	}
	else{
		cout << "1 " << N <<endl;
		for(int i = 0; i < N-1; i++){
			long long int sub = -arr[i]*N;
			cout << sub << " ";
		}
		cout << "0";
		cout << endl << "1 " << N-1 <<endl;
		for(int i = 0; i < N-1; i++){
			long long int add = arr[i]*(N-1);
			cout << add << " ";
		}
		cout << endl;
		cout << N << " " << N <<endl;
		cout << -arr[N-1];
	}
}