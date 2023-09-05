#include <fstream>
#include <vector>

using namespace std;
#define MAXN 505
ifstream cin("brownie.in");
ofstream cout("brownie.out");
int arr[MAXN][MAXN];
int ps[MAXN][MAXN];
int r,c,a,b;

bool isPossible(int size){
	int lastL = -1;
	int curL = 0;
	for(int i =0; i < a; i++){
		while(curL < r && ps[curL][c-1] - ((lastL == -1) ? 0 : ps[lastL][c-1]) < size*b){
			curL++;
		}
		// cout << "current layer: " << curL << ", i: " << i << ", lastL: " << lastL <<endl;
		// cout << ps[curL][c-1] << " , " << ((lastL == -1) ? 0 : ps[lastL][c-1]) << " size*b: " << size*b<<endl;
		if(a-i > r-curL || curL == r){
		// cout << "failed!! sizze: " << size << endl;
			return false;
		} 
		bool skip = false;
		int lastJ = -1;
		int curJ = 0;
		int curSize = 0;
		for(int j =0; j < b; j++){
			if(lastL == -1 && lastJ == -1){
				curSize = ps[curL][curJ];
			}
			else if(lastL == -1){
				curSize = ps[curL][curJ]-ps[curL][lastJ];
			}
			else if(lastJ == -1){
				curSize = ps[curL][curJ]-ps[lastL][curJ];
			}
			else{
				curSize = ps[curL][curJ]-ps[lastL][curJ]-ps[curL][lastJ]+ps[lastL][lastJ];	
			}
			// cout << "CURSIZE: " << curSize<<", lastJ " << lastJ << ", curJ" << curJ<<endl;
			while(curSize < size && curJ < c-1){
				curJ++;
				if(lastL == -1 && lastJ == -1){
					curSize = ps[curL][curJ];
				}
				else if(lastL == -1){
					curSize = ps[curL][curJ]-ps[curL][lastJ];
				}
				else if(lastJ == -1){
					curSize = ps[curL][curJ]-ps[lastL][curJ];
				}
				else{
					// cout << "calculated here: " << ps[curL][curJ] << ", " << ps[lastL][curJ] << ", " << ps[curL][lastJ] << ", " <<ps[lastL][lastJ]<<endl;
					curSize = ps[curL][curJ]-ps[lastL][curJ]-ps[curL][lastJ]+ps[lastL][lastJ];	
				}
				// cout << "CURSIZE: " << curSize<<", lastJ " << lastJ << ", curJ" << curJ<<endl;
			}
				// cout << "CURSIZE: " << curSize<<", lastJ " << lastJ << ", curJ" << curJ<<endl;
			if(curSize < size || b-j > c-lastJ){
				skip = true;
				i--;
				curL++;
				break;
			}
			lastJ = curJ;
			curJ++;
		}
		if(skip) continue;
		lastL = curL;
		curL++;
	}
	// cout << "yes: \n";
	// cout << "PASSED!! sizze: " << size << endl;
	return true;
}

int main(){

	cin >> r >> c >> a >> b;
	for(int i =0; i< r; i++){
		for(int j=0; j < c; j++){
			cin >> arr[i][j];
		}
	}
	ps[0][0] = arr[0][0];
	for(int i=0; i < r; i++){
		for(int j =0; j < c; j++){
			if(i == 0 && j == 0) continue;
			if(i == 0){
				ps[i][j] = arr[i][j] + ps[i][j-1];
				continue;
			}
			if(j == 0){
				ps[i][j] = arr[i][j] + ps[i-1][j];
				continue;
			}

			ps[i][j] = arr[i][j] + ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1];
		}
	}
	// for(int i=0; i < r; i++){
	// 	for(int j =0; j < c; j++){
	// 		cout << ps[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = 0;
	int i = 0;
	int j = r*c*4000/a/b;
	while( i < j){
		int mid = (i+j)/2;
		// cout << "mid: " << mid << ", " <<isPossible(mid)<<endl;
		if(isPossible(mid)){
			ans = max(ans,mid);
			i = mid+1;
		}
		else{
			j=mid;
		}
	}
	// isPossible(46950);
	cout << ans;
}