#include <bits/stdc++.h>
using namespace std;

void solve(){
    string a,b;
    cin >> a >> b;
    int as = a.size();
    int bs = b.size();
    map<int,int> mp;
    if(a[0] == b[0]){
        string res;
        res+=a[0];
        res+="*";
        cout << "YES\n" << res << "\n";
        return;
    }
    if(a[as-1] == b[bs-1]){
        string res = "*";
        res+=a[as-1];
        cout << "YES\n" << res << "\n";
        return;
    }
    for(int i = 0; i < as-1; i++){
        int hsh = (a[i]-'a')*30+(a[i+1]-'a');
        mp[hsh] = 1;
    }
    for(int i = 0; i < bs-1; i++){
        int hsh = (b[i]-'a')*30+(b[i+1]-'a');
        if(mp.count(hsh) > 0){
            string res = "*";
            res+=b[i];
            res+= b[i+1];
            res+="*";
            cout << "YES\n" << res << "\n";
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
