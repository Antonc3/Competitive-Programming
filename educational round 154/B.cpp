#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.length();
    vector<int> prefix(n,0);
    vector<int> suffix(n,0);
    prefix[0] = 1;
    suffix[n-1] = 1;
    for(int i = 1; i < n; i++){
        if(a[i]==b[i]){
            //then either the prefix or suffix is done
            if(a[i] == '0'){
                prefix[i] = 1;
            }
            if(a[i] == '1'){
                suffix[i] = 1;
                prefix[i] = prefix[i - 1];
            }
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(a[i] == b[i]){
            if(suffix[i+1]){
                suffix[i] = suffix[i + 1];
            }
        }
        if(prefix[i] && suffix[i]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}