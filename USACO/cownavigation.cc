#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

//0 passable
//1 wall

int barn[20][20];

int n;

//directions, 0 looking up, 1 looking left, 2 looking down, 3 looking right

int dist[20][20][4][20][20][4];

int dX[4] = {0,1,0,-1};
int dY[4] = {-1,0,1,0};

int bfs(){
	queue<pair<pair<int,pair<int,int>>,pair<int,pair<int,int>>>> q;
	q.push({{0,{n-1,0}},{0,{n-1,1}}});
	for(int i =0; i < n; i++){
		for(int j =0; j < n; j++){
			for(int k = 0; k < 4; k++){
				for(int ii = 0; ii < n; ii++){
					for(int jj = 0; jj < n; jj++){
						for(int kk = 0; kk < 4; kk++){
							dist[i][j][k][ii][jj][kk] = -1;
						}
					}
				}
			}
		}
	}
	dist[n-1][0][0][n-1][0][1] = 0;
	while(!q.empty()){
		pair<pair<int,pair<int,int>>,pair<int,pair<int,int>>> t = q.front();q.pop();
		int aX = t.f.f;
		int aY = t.f.s.f;
		int bX = t.s.f;
		int bY = t.s.s.f;
		// cout << aX << ", " << aY << ", " << t.f.s.s<<", B: " << bX << ", " << bY << ", " << t.s.s.s<<endl;
		if(aX == n-1 && bX == n-1 && bY == 0 && aY == 0) {
			// break
			return dist[0][n-1][t.f.s.s][0][n-1][t.s.s.s];
		}

		for(int i = -1; i <=1; i++){
			int aDir = (t.f.s.s+i)%4;
			if(aDir == -1) aDir = 3;
			int bDir = (t.s.s.s+i)%4;
			if(bDir == -1) bDir = 3;
			int nAX = max(0,min((aX+dX[aDir]),n-1));
			int nAY = max(0,min((aY+dY[aDir]),n-1));
			int nBX = max(0,min((bX+dX[bDir]),n-1));
			int nBY = max(0,min((bY+dY[bDir]),n-1));
		// cout << nAX << ", " << nAY << ", " << aDir<<", B: " << nBX << ", " << nBY << ", " << bDir<<endl;
			if(barn[nAY][nAX] || (aX == n-1 && aY == 0)){
				nAX = aX;
				nAY = aY;
			}
			if(barn[nBY][nBX] || (bX == n-1 && bY == 0)){
				nBX = bX;
				nBY = bY;
			}
			if(i == 0){
				if(dist[nAY][nAX][aDir][nBY][nBX][bDir] == -1){
					// cout << "INHERE!"<<endl;
					q.push({{nAX,{nAY,aDir}},{nBX,{nBY,bDir}}});
					dist[nAY][nAX][aDir][nBY][nBX][bDir] = dist[aY][aX][t.f.s.s][bY][bX][t.s.s.s]+1;
				}
				continue;
			}
			if(dist[aY][aX][aDir][bY][bX][bDir] == -1){
				// cout << "INHERE111!!"<<endl;
				q.push({{aX,{aY,aDir}},{bX,{bY,bDir}}});
				dist[aY][aX][aDir][bY][bX][bDir] = dist[aY][aX][t.f.s.s][bY][bX][t.s.s.s]+1;
			}
			
		}
	}
	int ans = 999999999;
	for(int i =0; i < 4; i++){
		for(int j = 0; j <4;j++){
			ans = min(ans,dist[0][n-1][i][0][n-1][j]);
		}
	}
	return ans;
}

int main(){
	freopen("cownav.in","r",stdin);
	freopen("cownav.out","w",stdout);
	cin >> n;
	for(int i =0; i < n; i++){
		for(int j =0; j < n; j++){
			char c;
			cin >> c;
			if(c == 'H') barn[i][j] = 1;
			else barn[i][j] = 0;
		}
	}
	cout << bfs();
}