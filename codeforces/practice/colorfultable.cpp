#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> colors(k);
    set<int> m;
    for(int i =0; i < n; i++){
        int c;
        cin >> c;
        c--;
        colors[c].push_back(i);
        m.insert(i);
    }
    for(int i =0; i < k; i++){
        if(colors[i].size() == 0){
            cout << "0 ";
            continue;
        }
        int mn = *m.begin();
        int mx = *m.rbegin();
        for(auto x : colors[i]){
            m.erase(x);
        }
        cout << (mx-mn+1)*2 << " ";
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