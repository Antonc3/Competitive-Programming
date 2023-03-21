#include <bits/stdc++.h>
using namespace std;

int n;
void solve(){
    cin >> n;

    vector<string> ss;
    for(int i = 0; i < 2*n-2; i++){
        string s;
        cin >> s;
        if(s.length() == n/2){
            ss.push_back(s);
        }
    }
    bool good = true;
    //c0out << "FOUND: " << ss[0] << " " << ss[1] << endl;
    for(int i = 0; i < n/2; i++){
        if(ss[0][i] != ss[1][n/2-i-1]) good = false;
    }
    if(good){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
