#include <bits/stdc++.h>
using namespace std;
string s;
void solve(){
    vector<int> digits(10,0);
    cin >> s;
    // vector<bool> used(s.length(), false);
    int prevLast = 0;
    // string test = "abcdefghiji";
    // cout <<"test: " << test << " -- " <<  test.find_last_of('i')<<endl;
    // cout << s << endl;
    // cout << "test 2: " << s.find_last_of('7')<<endl;
    
    for(int i = 0; i < 10; i++){
        char curchar = ('0'+i);
        int lastDig = s.find_last_of(curchar);
        // cout << "last dig: "<<lastDig << endl;
        // cout << "curchar: " << curchar<<endl;
        if(lastDig == string::npos || lastDig < prevLast) continue; 
        for(int j = prevLast; j <= lastDig; j++){
            // cout << "s[j]" << s[j] << endl;
            if(s[j] == curchar) digits[i]++;
            else if(s[j] == '9') digits[9]++;
            else digits[s[j]-'0'+1]++;
            // cout << s[j]-'0'<<endl;
        }
        prevLast = lastDig+1;
    }
    string ans = "";
    for(int i = 0; i < 10; i++){
        int cnt = 0;
        while(cnt++ < digits[i]){
            ans += ('0'+i);
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