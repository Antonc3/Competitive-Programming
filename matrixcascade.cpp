#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> M(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            M[i][j] = s[j]-'0';
        }
    }
    vector<vector<pair<int,int>>> propogate(n,vector<pair<int,int>>(n,{0,0}));
    int ans = 0;
    for(int i =0 ; i < n; i++){
        int cur = 0;
        for(int j =0; j < n; j++){
            if(propogate[i][j].first){
                cur = !cur;
                if(i < n-1){
                    propogate[i + 1][max(0, j - 1)].first = !propogate[i + 1][max(0, j - 1)].first;
                }
            } 
            if(propogate[i][j].second){
                cur = !cur;
                if(i < n-1 && j < n-1){
                    propogate[i+1][j+1].second = !propogate[i+1][j+1].second;
                }
            }
            if(cur) M[i][j] = !M[i][j];
            if(M[i][j]){
                ans++;
                if(i < n-1){
                    propogate[i + 1][max(0, j - 1)].first = !propogate[i + 1][max(0, j - 1)].first;
                }
                if(i < n-1 && j < n-2){
                    propogate[i+1][j+2].second = !propogate[i+1][j+2].second;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}