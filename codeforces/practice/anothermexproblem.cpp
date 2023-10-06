#include <bits/stdc++.h>
using namespace std;
#define MAXN 5050

int dp[MAXN][2*MAXN];

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a){
         cin >> x;
    }
    for(int i =0 ; i <= n; i++){
        fill(dp[i],dp[i]+2*MAXN,0);
    }

    dp[0][0] = 1;
    vector<int> seenMex(n+1,-1);
    for(int i = 1; i <= n; i++){
        bool check =false;
        vector<int> seen(n+5,0);
        int mex = 0;
        for(int j = i; j >= 1; j--){
            seen[a[j-1]] = 1;
            while(seen[mex]){
                mex++;
                check = true;
            }
            if(seenMex[j] != mex){
                if(check){
                    for (int k = 2 * MAXN - 1; k >= 0; k--)
                    {
                        dp[i][k ^ mex] |= dp[j - 1][k];
                    }
                    check = false;
                }
                seenMex[j] = mex;
            }
        }
        for(int j =0; j < MAXN*2; j++){
            dp[i][j] |= dp[i-1][j];
        }
    }
    for(int i = 2*MAXN-1; i >= 0; i--){
        if(dp[n][i]){
            cout << i << endl;
            return;
        } 
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}