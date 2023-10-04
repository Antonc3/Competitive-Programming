#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<string,int> backHash2, backHash23;
    map<string,int> backHash3;
    bool good = false;
    for(int i =0 ; i < n; i++){
        string s;
        cin >> s;
        if(s.length() == 1) good = true;
        else if (s.length() == 2){
            if(s[0] == s[1]) good = true;
            string s2 = s;
            reverse(s2.begin(),s2.end());
            if(backHash2[s2] == 1){
                good = true;
            }
            if(backHash23[s2] == 1){
                good = true;
            }
            backHash2[s] = 1;
        }
        else{
            if(s[0] == s[2]) good = true;
            string fronttwochars = s.substr(0,2);
            string backtwochars = s.substr(1,2);
            reverse(backtwochars.begin(),backtwochars.end());
            string s2 = s;
            reverse(s2.begin(),s2.end());
            if(backHash3[s2] == 1){
                good = true;
            }
            if(backHash2[backtwochars]){
                good = true;
            }
            backHash3[s] = 1;
            backHash23[fronttwochars] = 1;
        }
    }
    cout << ((good) ?  "YES" : "NO") << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}