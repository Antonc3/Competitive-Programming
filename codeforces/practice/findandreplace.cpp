#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> remap(30,-1);
    remap[s[0]-'a'] = 1;
    for(int i = 1; i < n; i++){
        if(remap[s[i]-'a'] == -1){
            remap[s[i]-'a'] = !remap[s[i-1]-'a'];
        }
        if(remap[s[i]-'a'] == remap[s[i-1]-'a']) {
            cout <<"NO\n";
            return;
        }
    }
    cout <<"YES\n";
}
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
