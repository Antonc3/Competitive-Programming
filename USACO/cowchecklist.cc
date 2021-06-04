#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

#define f first
#define s second
#define MAXN 1001
pair<int,int> cows[MAXN][2];

int h,g;
long long dp[MAXN][MAXN][2];

int dist(pair<int,int> a, pair<int,int> b){
	return (a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s);
}

int main(){	
	ifstream cin ("checklist.in");
	ofstream cout ("checklist.out");

	cin >> h >> g;
	for(int i =0; i < h; i++){
		int a,b;
		cin >> a >> b;
		cows[i][0] = {a,b};
	}
	for(int i =0; i < g; i++){
		int a,b;
		cin >> a >> b;
		cows[i][1] = {a,b};
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[1][0][0] = 0;
	dp[1][0][1] = 0;
	dp[0][1][1] = 0;
	dp[0][1][0] = 0;
	for(int i =0; i <= h; i++){
		for(int j =0; j <= g; j++){
			for(int s = 0; s < 2; s++){
				//s = 0 then hurn
				//s = 1 then gurn
				if(i == 0 && j == 0) continue;
				if(i == 0){
					// if(s == 0){
						dp[i][j][s] = 9999999999;
						continue;
					// }
					// if(j == 1) continue;
					// dp[i][j][s] = dp[i][j-1][s] + dist(cows[j-2][1],cows[j-1][1]);
					// continue;
				}
				if(j == 0){
					if(s==1){
						dp[i][j][s] = 9999999990;
						continue;
					}
					if(i == 1) continue;
					dp[i][j][s] = dp[i-1][j][s] + dist(cows[i-2][0],cows[i-1][0]);
					continue;
				}
				// cout << "i,j,s" << i << ", " << j << ", " <<s<<endl;
				if(s){
					//gurn
					if(j == 1){
						dp[i][j][s] = dp[i][j-1][0]+dist(cows[i-1][0],cows[j-1][1]);
						continue;
					}
					dp[i][j][s] = min(dp[i][j-1][0] + dist(cows[i-1][0],cows[j-1][1]), dp[i][j-1][1]
						+dist(cows[j-2][1],cows[j-1][1]));
				}
				else{
					//hern
					if(i == 1){
						dp[i][j][s] = dp[i-1][j][1]+dist(cows[j-1][1],cows[i-1][0]);
						continue;
					}
					dp[i][j][s] = min(dp[i-1][j][0] + dist(cows[i-2][0],cows[i-1][0]), dp[i-1][j][1]
						+dist(cows[j-1][1],cows[i-1][0]));
				}
				// cout <<endl;
			}
		}
	}
	// for(int s = 0; s < 2; s++){
	// 		for(int j =0; j <= g; j++){

	// 	for(int i = 0; i <= h; i++){
	// 			cout << dp[i][j][s]<< " ";
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << "\n\n\n";
	// }
	cout << dp[h][g][0];
}