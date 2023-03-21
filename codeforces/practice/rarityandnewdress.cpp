#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005

char grid[MAXN][MAXN];
int diamonds[MAXN][MAXN];
int dpdown[MAXN][MAXN];
int dpup[MAXN][MAXN];
int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            dpup[i][j] = 1;
            dpdown[i][j] = 1;
        }
    }
    int dx[] = {-1, 1, 0};
    int dy[] = {0, 0, -1};

    for(int i = 1; i < n; i++){
        vector<int> right(m);
        for(int c = m-1; c >= 0; c--){
            int cnt = 1;
            while(c > 0 &&grid[i][c] == grid[i][c-1]){
                right[c] = cnt;
                cnt++;
                c--;
            }
            right[c] = cnt;
        }
        vector<int> left(m);
        for(int c = 0; c < m; c++){
            int cnt = 1;
            while(c < m-1 &&grid[i][c] == grid[i][c+1]){
                left[c] = cnt;
                cnt++;
                c++;
            }
            left[c] = cnt;
        }
        for(int j = 0; j < m; j++){
            if(grid[i-1][j] == grid[i][j]){
                dpup[i][j] =  min({dpup[i-1][j]+1,left[j],right[j]});
            }
        }
    }
    for(int i = n-2; i >= 0; i--){
        vector<int> right(m);
        for(int c = m-1; c >= 0; c--){
            int cnt = 1;
            while(c > 0 &&grid[i][c] == grid[i][c-1]){
                right[c] = cnt;
                cnt++;
                c--;
            }
            right[c] = cnt;
        }
        vector<int> left(m);
        for(int c = 0; c < m; c++){
            int cnt = 1;
            while(c < m-1 &&grid[i][c] == grid[i][c+1]){
                left[c] = cnt;
                cnt++;
                c++;
            }
            left[c] = cnt;
        }
        for(int j = 0; j < m; j++){
            if(grid[i+1][j] == grid[i][j]){
                dpdown[i][j] =  min({dpdown[i+1][j]+1,left[j],right[j]});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans+=min(dpup[i][j],dpdown[i][j]);
        }
        //cout << endl;
    }
    cout << ans << endl;
}
