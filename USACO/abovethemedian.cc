#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define MAXN 100005

int arr[MAXN];
int ft[2*MAXN];
int n,x;

void upd(int x){
	for(x+=MAXN; x < 2*MAXN; x+=(x&-x)){
		ft[x]++;		
	}
}

int query(int x){
	int sum =0;
	for(x+=MAXN; x > 0; x-=(x&-x)){
		sum+=ft[x];
	}
	return sum;
}
int main(){
	ifstream cin("median.in");
	ofstream cout("median.out");
	cin >> n >> x;
	for(int i =0; i < n; i++){
		int a;
		cin >> a;
		if(a >= x){
			arr[i] = 1;
		}
		else{
			arr[i] = -1;
		}
	}
	long long ans =0;
	int s = 0;
	upd(0);
	for(int i =0; i < n; i++){
		s+=arr[i];
		ans+=query(s);
		upd(s);
	}
	cout << ans;
}