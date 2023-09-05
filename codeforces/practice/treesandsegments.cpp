#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> pref(n+1,vector<int>(k+1,0));
    vector<vector<int>> suff(n+1,vector<int>(k+1,0));
    for(int i =0 ; i < n; i++){
        for(int j=0; j <= k; j++){
            if(s[i] == '0'){
                pref[i][j] = ((i > 0) ? pref[i-1][j] : 0) + 1;
            }
            else{
                if(j > 0){
                    pref[i][j] = ((i > 0) ? pref[i - 1][j-1] : 0) + 1;
                }
                else{
                    pref[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j =0; j <= k; j++){
            if(i > 0) pref[i][j] = max(pref[i][j],pref[i-1][j]);
        }
    }
    for(int i =n-1 ; i >=0; i--){
        for(int j=0; j <= k; j++){
            if(s[i] == '0'){
                suff[i][j] = ((i <n-1) ? suff[i+1][j] : 0) + 1;
            }
            else{
                if(j > 0){
                    suff[i][j] = ((i < n-1) ? suff[i + 1][j-1] : 0) + 1;
                }
                else{
                    suff[i][j] = 0;
                }
            }
        }
    }
    for(int i = n-1; i >=0; i--){
        for(int j =0; j <= k; j++){
            if(i < n-1) suff[i][j] = max(suff[i][j],suff[i+1][j]);
            //cout << suff[i][j] << " ";
        }
        //cout << endl;
    }
    vector<int> zerocount(n);
    for(int i = 0; i < n; i++){
        if(i > 0) zerocount[i] = zerocount[i-1];
        if(s[i] == '0'){
            zerocount[i]++;
        }
        //cout << zerocount[i] << " ";
    }
    //cout << endl;
    vector<int> mostzeroes(n+1,-1);
    mostzeroes[0] = pref[n-1][k];
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            int cost = zerocount[r];
            if(l-1 >= 0) cost-=zerocount[l-1];
            //if(l-1 >= 0) cout << zerocount[l-1] << " " << zerocount[r]<< endl;
            if(cost > k) break;
            int b = 0;
            if(cost <= k && r < n-1) b = suff[r+1][k-cost];
            if(cost <= k && l > 0) b= max(b,pref[l-1][k-cost]);
            //cout << "b: " << b << " r: " << r << " l " << l << "COIST : " << cost << endl;
            mostzeroes[(r-l)+1] = max(mostzeroes[(r-l+1)], b);
        }
    }
    for(int a = 1; a <= n; a++){
        int best = 0;
        for(int i = 0; i <= n; i++){
            if(mostzeroes[i] == -1) continue;
            best = max(best,i + a*mostzeroes[i]);
        }
        cout << best << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}