#include <bits/stdc++.h>
using namespace std;
#define MAXN 205
typedef long long ll;
int arr[3][MAXN];
ll dp[MAXN][MAXN][MAXN];
int main(){
    vector<int> len(3);
    for(int &x : len) cin >> x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < len[i]; j++) cin >> arr[i][j];
        sort(arr[i],arr[i]+len[i]);
        reverse(arr[i],arr[i]+len[i]);
    }
    ll best = 0;
    for(int a = 0; a <= len[0]; a++){
        for(int b = 0; b <= len[1]; b++){
            for(int c = 0; c <= len[2]; c++){
                if(a < len[0] && b < len[1]) dp[a+1][b+1][c] = max(dp[a+1][b+1][c],dp[a][b][c]+arr[0][a]*arr[1][b]); 
                if(a < len[0] && c < len[2]) dp[a+1][b][c+1] = max(dp[a+1][b][c+1],dp[a][b][c]+arr[0][a]*arr[2][c]); 
                if(b < len[1] && c < len[2]) dp[a][b+1][c+1] = max(dp[a][b+1][c+1],dp[a][b][c]+arr[2][c]*arr[1][b]); 
                best = max(best,dp[a+1][b+1][c]);
                best = max(best,dp[a+1][b][c+1]);
                best = max(best,dp[a][b+1][c+1]);
                //cout << " a: " << a << " b " << b << " c " << c << endl;
                //cout << best << endl;
            }
        }
    }
    cout << best << endl;
}
