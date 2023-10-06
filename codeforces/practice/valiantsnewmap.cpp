#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int n,m;
bool check(int x){
    vector<vector<int>> horiz(n,vector<int>(m-x+1));
    for(int i =0; i < n; i++){
        int l = 0, r = 0;
        int gc = 0, bc = 0;
        while(r < m){
            while (r < m && r - l < x)
            {
                if(board[i][r] >= x) gc++;
                else bc++;
                r++;
            }
            horiz[i][l] = bc==0;
            if (board[i][l] >= x)
                gc--;
            else
                bc--;
            l++;
        }
    }
    for(int i =0; i <= m-x; i++){
        int l = 0, r = 0;
        int gc = 0, bc = 0;
        while(r < n){
            while (r < n && r - l < x)
            {
                if(horiz[r][i]==1) gc++;
                else bc++;
                r++;
            }
            if(bc==0){
                return true;
            }

            if (horiz[l][i] == 1)
                gc--;
            else
                bc--;
            l++;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    board.resize(n,vector<int>());
    for(int i =0; i < n; i++){
        board[i].clear();
        for(int j =0; j < m; j++){
            int x;
            cin >> x;
            board[i].push_back(x);
        }
    }
    int l = 2, r = min(n,m);
    int best = 1;
    while( l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            best = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << best << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}