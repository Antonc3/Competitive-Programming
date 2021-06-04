#include <algorithm>
#include <fstream>
#include <map>
using namespace std;
#define MAXN 20000

map<int,int> arr[5];
int ans[MAXN];
int n;
bool cmp(int a, int b){
	int cnt = 0;
	for(int i =0; i < 5; i++){
		cnt+=arr[i][a] < arr[i][b];
	}
	return (cnt>2);
}

int main(){
	ifstream cin("photo.in");
	ofstream cout("photo.out");
	cin >> n;
	for(int i =0; i < 5; i++){
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			arr[i][x] = j;
			ans[j] =x;
		}
	}
	sort(ans,ans+n,cmp);
	for(int i =0; i < n; i++){
		cout << ans[i] << "\n";
	}
}