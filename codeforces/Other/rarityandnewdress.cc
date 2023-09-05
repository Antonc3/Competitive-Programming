#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int n,m;
char arr[2000][2000];
int dp[2000][2000];

int dirX[] = {1,0,-1,0};
int dirY[] = {0,1,0,-1};

bool hasNext(int row, int col){
	int cur = dp[row][col];
	for(int i =0; i < 4; i++){
		if(row+dirY[i] < 0 || row+dirY[i] >= n || col+dirX[i] < 0 || col+dirX[i] >= n){
			return false;
		}
		if(dp[row+dirY[i]][col+dirX[i]] >= cur && arr[row+dirY[i]][col+dirX[i]] == arr[row][col]){
			continue;
		}
		return false;
	}
	dp[row][col]++;
	return true;
}

int main(){
	cin >> n >> m;
	queue<pair<int,int>> q;

	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			q.push({i,j});
		}
	}
	memset(dp,0,sizeof(dp[0][0])*4000000);
	int result = 0;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		if(hasNext(cur.first,cur.second)){
			q.push({cur.first,cur.second});
		}
		result++;
	}
	cout << result;
}