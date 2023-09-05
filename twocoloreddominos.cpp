#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> board(n);
    vector<string> ans(n);
    vector<int> col(m,0);
    vector<int> row(n,0);
    bool good = true; 
    for(int i =0; i < n; i++){
        cin >> board[i];
        ans[i] = board[i];
        for(int j = 0;j < m; j++){
            ans[i][j] = '.';
            if(board[i][j] == 'L'){
                col[j]++;
                col[j+1]++;
            }
            else if(board[i][j] == 'U' || board[i][j] == 'D') row[i]++;
        }
    }
    for(int i : col) if(i&1) good = false;
    for(int i : row) if(i&1) good = false;
    if(!good){
        cout << "-1\n";
        return;
    }
    for(int i =0; i < n-1; i++){
        int toColor = row[i];
        int cw = 0;
        for(int j =0;j < m; j++){
            if(board[i][j] == 'U'){
                ans[i][j] = (cw>=toColor/2) ? 'W' : 'B';
                ans[i+1][j] = (cw<toColor/2) ? 'W' : 'B';
                cw++;
            }
        }
        row[i+1] -=row[i];
    }
    for(int j =0; j < m-1; j++){
        int toColor = col[j];
        int cw = 0;
        for(int i =0;i < n; i++){
            if(board[i][j] == 'L'){
                ans[i][j] = (cw>=toColor/2) ? 'W' : 'B';
                ans[i][j+1] = (cw<toColor/2) ? 'W' : 'B';
                cw++;
            }
        }
        col[j+1] -=col[j];
    }
    for(string s : ans){
        cout << s << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}