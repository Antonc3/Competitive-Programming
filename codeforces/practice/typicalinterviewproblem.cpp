#include <bits/stdc++.h>
using namespace std;

void solve(){
    string pattern = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    int n; cin >> n;
    string s;
    cin >> s;
    for(int i =0; i < pattern.length()-n; i++){
        bool good = true;
        for(int j = 0; j <n; j++){
            if(s[j] != pattern[i+j]) good = false;
        }
        if(good){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

//FBFFBFF
//FBFFBFF
int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
