#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int one = -1;
    int seven = -1;
    for(int i =0 ; i < 9; i++){
        if(s[i] == '1') one = i;
        if(s[i] == '7') seven = i;
    }
    if(seven > one) cout << "17\n";
    else cout << "71\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}