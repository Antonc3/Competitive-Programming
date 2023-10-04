#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> board(n,vector<int>(m));
    if(m == 1){
        cout << 0<<endl;
        for(int i = 0; i < n; i++) cout << "0\n";
        return;
    }
    int ans = min(n+1,m);
    cout << ans << endl;
    int lastrow = ans-1;
    for(int i = 0; i < ans; i++){
        int start = (i+1)%ans;
        for(int j =0; j < lastrow; j++){
            board[j][start] = i;
            start = (start+1)%ans;
        }
    }
    for(int i = ans; i < m; i++){
        for(int j = 0; j < n; j++){
            board[j][i] = i;
        }
    }
    if(ans > 1){
        for (int i = ans - 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = board[i - 1][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    //nxn 3x3
    // 2 1 0
    // 1 2 0
    // 1 0 1
    // 4x4
    // 3 2 1 0
    // 3 1 0 2
    // 1 0 3 2
    // 1 0 3 2
    // 5x5
    // 4 0 1 2 3
    // 3 4 0 1 2
    // 2 3 4 0 1
    // 1 2 3 4 0
    // 1 2 3 4 0
    // 5x6
    // 5 0 1 2 3 4
    // 4 5 0 1 2 3
    // 3 4 5 0 1 2
    // 2 3 4 5 0 1
    // 1 2 3 4 5 0
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}